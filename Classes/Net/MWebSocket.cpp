//
//  MWebSocket.cpp
//  Mahjong
//
//  Created by tiki on 14/10/27.
//
//

#include "MWebSocket.h"
#include "Tools/HMessage.h"
USING_NS_CC;
USING_NS_CC_EXT;

MWebSocket::MWebSocket()
: _wsiSendText(nullptr)
, _wsiSendBinary(nullptr)
, _wsiError(nullptr)
, _sendTextTimes(0)
, _sendBinaryTimes(0)
,_hasNewMessage(false)
,_hasConnectedOk(false)
{
    
}

MWebSocket::~MWebSocket()
{
    if (_wsiSendText)
        _wsiSendText->close();
    
    if (_wsiSendBinary)
        _wsiSendBinary->close();
    
    if (_wsiError)
        _wsiError->close();
}

bool MWebSocket::init()
{
    _wsiSendText = new network::WebSocket();
    _wsiSendBinary = new network::WebSocket();
    _wsiError = new network::WebSocket();
    
//    if (!_wsiSendText->init(*this, "ws://10.80.100.115:8081/websocket"))
//    {
//        CC_SAFE_DELETE(_wsiSendText);
//    }
//    
//    if (!_wsiSendBinary->init(*this, "ws://10.80.100.115:8081/websocket"))
//    {
//        CC_SAFE_DELETE(_wsiSendBinary);
//    }
//    
//    if (!_wsiError->init(*this, "ws://invalid.url.com"))
//    {
//        CC_SAFE_DELETE(_wsiError);
//    }
//    if (!_wsiSendText->init(*this, "ws://echo.websocket.org"))
//    {
//        CC_SAFE_DELETE(_wsiSendText);
//    }
    
    if (!_wsiSendBinary->init(*this, "ws://echo.websocket.org"))
    {
        CC_SAFE_DELETE(_wsiSendBinary);
    }
    
//    if (!_wsiError->init(*this, "ws://invalid.url.com"))
//    {
//        CC_SAFE_DELETE(_wsiError);
//    }
    return true;
}

void MWebSocket::onOpen(network::WebSocket* ws)
{
    log("Websocket (%p) opened", ws);
    if (ws == _wsiSendText)
    {
        CCLOG("Send Text WS was opened.");
    }
    else if (ws == _wsiSendBinary)
    {
        CCLOG("Send Binary WS was opened.");
        setHasConnectedOk(true);
    }
    else if (ws == _wsiError)
    {
        CCASSERT(0, "error test will never go here.");
    }
}

void MWebSocket::onClose(cocos2d::network::WebSocket *ws)
{
    log("websocket instance (%p) closed.", ws);
    if (ws == _wsiSendText)
    {
        _wsiSendText = nullptr;
    }
    else if (ws == _wsiSendBinary)
    {
        _wsiSendBinary = nullptr;
        setHasConnectedOk(false);
    }
    else if (ws == _wsiError)
    {
        _wsiError = nullptr;
    }
    // Delete websocket instance.
    CC_SAFE_DELETE(ws);
}

void MWebSocket::onMessage(cocos2d::network::WebSocket *ws, const cocos2d::network::WebSocket::Data &data)
{
    if (!data.isBinary)
    {
        _sendTextTimes++;
        char times[100] = {0};
        sprintf(times, "%d", _sendTextTimes);
        std::string textStr = std::string("response text msg: ")+data.bytes+", "+times;
        log("%s", textStr.c_str());
    }
    else
    {
        _sendBinaryTimes++;
        char times[100] = {0};
        sprintf(times, "%d", _sendBinaryTimes);
        
        char* recvBuf = data.bytes;
        
        auto mess1 = new HMessage((uint8_t*)recvBuf,data.len);
        CCLOG("%s--->",mess1->getBuf());
        std::string binaryStr;
        for (int i = 0; i < data.len; ++i) {
            if (data.bytes[i] != '\0')
            {
                binaryStr += data.bytes[i];
            }
            else
            {
//                binaryStr += "\'\\0\'";
            }
        }
        
        HMessage* mess = new HMessage((uint8_t*)binaryStr.c_str(),data.len);
        CCLOG("%s",mess->getBuf());
        binaryStr += std::string(", ")+times;
        log("%s", binaryStr.c_str());
    }
}

void MWebSocket::onError(network::WebSocket* ws, const network::WebSocket::ErrorCode& error)
{
    log("Error was fired, error code: %d", error);
    if (ws == _wsiError)
    {
        char buf[100] = {0};
        sprintf(buf, "an error was fired, code: %d", error);
        log("%s",buf);
    }
}

void MWebSocket::send(HMessage* mess)
{
    if (! _wsiSendBinary)
    {
        return;
    }
    
    if (_wsiSendBinary->getReadyState() == network::WebSocket::State::OPEN)
    {
        uint8_t* buffer = mess->getBuf();
        _wsiSendBinary->send((unsigned char*)buffer,mess->getlengths());
    }
    else
    {
        std::string warningStr = "send text websocket instance wasn't ready...";
        log("%s", warningStr.c_str());
    }
}
void MWebSocket::close()
{
    if (_wsiSendText)
        _wsiSendText->close();
    
    if (_wsiSendBinary)
        _wsiSendBinary->close();
    
    if (_wsiError)
        _wsiError->close();
}

//
//  MWebSocket.h
//  Mahjong
//
//  Created by tiki on 14/10/27.
//
//

#ifndef __Mahjong__MWebSocket__
#define __Mahjong__MWebSocket__

#include <stdio.h>
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "network/WebSocket.h"
#include "HMessage.h"

class MWebSocket : public cocos2d::network::WebSocket::Delegate
{
public:
    MWebSocket();
    virtual ~MWebSocket();
    bool init();
    virtual void onOpen(cocos2d::network::WebSocket* ws);
    virtual void onMessage(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data);
    virtual void onClose(cocos2d::network::WebSocket* ws);
    virtual void onError(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error);
    
    // 发送消息
    void send(HMessage* mess);
    // 关闭消息
    void close();
    
    void toExtensionsMainLayer(cocos2d::Ref *sender);
private:
    cocos2d::network::WebSocket* _wsiSendText;
    cocos2d::network::WebSocket* _wsiSendBinary;
    cocos2d::network::WebSocket* _wsiError;
    
    
    int _sendTextTimes;
    int _sendBinaryTimes;
    // 是否有新消息
    CC_SYNTHESIZE(bool, _hasNewMessage, HasNewMessage);
    // 是否已连接上
    CC_SYNTHESIZE(bool, _hasConnectedOk, HasConnectedOk);
};
#endif /* defined(__Mahjong__MWebSocket__) */

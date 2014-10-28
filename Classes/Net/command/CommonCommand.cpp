//
//  CommonCommand.cpp
//  Mahjong
//
//  Created by tiki on 14/10/27.
//
//

#include "CommonCommand.h"
CommonCommand::CommonCommand()
:isClose(true)
,mSocket(NULL)
{
    
}

CommonCommand::~CommonCommand()
{
    mSocket = NULL;
}

bool CommonCommand::isConnectionOK = false;
bool CommonCommand::creatConnection(){
    isClose = false;
    mSocket = new MWebSocket();
    mSocket->init();
//    mSocket.Create(AF_INET, SOCK_STREAM,0);
//    CCLOG(GameData::getInstance()->getServerIp().c_str());
//    CCLOG("%d",GameData::getInstance()->getServerPort());
//    isConnectionOK = mSocket.Connect(GameData::getInstance()->getServerIp().c_str(),GameData::getInstance()->getServerPort());
    //	isConnectionOK = mSocket.Connect("10.80.1.14",30000);
//    if(isConnectionOK){
//        Data::isHeartSafe = true;
//        Data::isOutLine = false;
//        RoleModel::getInstance()->countnum = 0;
//    }
    
    return isConnectionOK;
}

MWebSocket* CommonCommand::getSocket(){
    return mSocket;
}
void CommonCommand::closeConnected(){
//    mSocket.Close();
//    mSocket.Clean();
    mSocket->close();
    isClose = true;
}
bool CommonCommand::isConnected(){
    isConnectionOK = mSocket->getHasConnectedOk();
    return isConnectionOK;
}
bool CommonCommand::isClosed(){
    isClose = mSocket->getHasConnectedOk();
    return isClose;
}
CommonCommand* CommonCommand::instance = NULL;
CommonCommand* CommonCommand::getInstance(){
    if(instance == NULL){
        instance = new CommonCommand();
        instance->creatConnection();
    }
    return instance;
}

void CommonCommand::stop(){
    if(instance != NULL){
        instance->closeConnected();
        instance = NULL;
    }
}
/*******************∑¢ÀÕ*************************/
bool CommonCommand::sendMessage(HMessage* mes){
    mSocket->send(mes);
//    HMessage* mess = new HMessage();
//    mess->putInt(mes->getlengths());
//    mess->putBytes(mes->getBuf(),mes->getlengths());
//    int result = mSocket->send((unsigned char*)(mess->getBuf()),mess->getlengths());
//    return (result != -1);
    return 1;
}
/******************Ω” ’**********************/
uint8_t CommonCommand::get(){
    char recvBuf[64] = "\0";
//    mSocket.Recv(recvBuf,1,0);
    HMessage* mess = new HMessage((uint8_t*)recvBuf,1);
    return mess->get();
}
uint16_t CommonCommand::getShort(){
    char recvBuf[64] = "\0";
//    mSocket.Recv(recvBuf,2,0);
    HMessage* mess = new HMessage((uint8_t*)recvBuf,2);
    return mess->getShort();
}
uint32_t CommonCommand::getInt(){
    char recvBuf[64] = "\0";
//    mSocket.Recv(recvBuf,4,0);
    HMessage* mess = new HMessage((uint8_t*)recvBuf,4);
    return mess->getInt();
}
uint64_t CommonCommand::getLong(){
    char recvBuf[64] = "\0";
//    mSocket->Recv(recvBuf,8,0);
    HMessage* mess = new HMessage((uint8_t*)recvBuf,8);
    return mess->getLong();
}
char* CommonCommand::getUTF8(){
    int strByteLen = getShort();
    char* recvBuf = new char[strByteLen*2];
//    mSocket.Recv(recvBuf,strByteLen,0);
    HMessage* mess = new HMessage((uint8_t*)recvBuf,strByteLen);
    return mess->getUTF8(strByteLen);
}

MWebSocket* CommonCommand::getmSocket(){
    return mSocket;
}
//
//  CommonCommand.h
//  Mahjong
//
//  Created by tiki on 14/10/27.
//
//

#ifndef __Mahjong__CommonCommand__
#define __Mahjong__CommonCommand__

#include <stdio.h>
#include "MWebSocket.h"
#include "HMessage.h"
class CommonCommand{
public:
    CommonCommand();
    ~CommonCommand();
    static CommonCommand* instance;
    static bool isConnectionOK;
    bool isClose;
    MWebSocket* mSocket;
    static CommonCommand* getInstance();
    void closeConnected();
    MWebSocket* getSocket();
    bool creatConnection();
    bool isConnected();
    bool isClosed();
    bool sendMessage(HMessage* mes);
    uint8_t get();
    uint16_t getShort();
    uint32_t getInt();
    uint64_t getLong();
    char* getUTF8();
    MWebSocket* getmSocket();
    void stop();
};
#endif /* defined(__Mahjong__CommonCommand__) */

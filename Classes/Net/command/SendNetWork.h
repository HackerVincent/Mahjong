//
//  SendNetWork.h
//  Mahjong
//
//  Created by tiki on 14/10/31.
//
//

#ifndef __Mahjong__SendNetWork__
#define __Mahjong__SendNetWork__

#include <stdio.h>
#include "cocos2d.h"
#include "RequestCommand.h"
class SendNetWork
{
public:
    SendNetWork();
    ~SendNetWork();
    static SendNetWork* instance;
    bool isRuning;
    bool isRunHeader;
    int reTryCount;
    std::vector<RequestCommand*> m_RequestCommandList;
    static SendNetWork* getInstance();
    void DealNetWorkThread();
    void stopNetWork();
    void sendCommandDataToServer();
    void AddNetCommand(RequestCommand* respCommand);
};
#endif /* defined(__Mahjong__SendNetWork__) */

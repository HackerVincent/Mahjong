//
//  NetLogic.cpp
//  Mahjong
//
//  Created by tiki on 14/10/30.
//
//

#include "NetLogic.h"
#include "Net/command/SendNetWork.h"
#include "command/CommonCommand.h"
using namespace cocos2d;

static NetLogic* s_netLogic = nullptr;

// 模拟消息层加入了场景中，不然schedule不执行
void NetLogic::onEnter()
{
    Node::onEnter();
}

void NetLogic::onExit()
{
    Node::onExit();
}


NetLogic::NetLogic()
{
    
}

NetLogic::~NetLogic()
{
    onExit();
    s_netLogic = nullptr;
}

bool NetLogic::init()
{
    bool bRet = false;
    do{
        CC_BREAK_IF(!Node::init());
        onEnter();
        schedule(schedule_selector(NetLogic::sendLogic), 0.1f);
        schedule(schedule_selector(NetLogic::sendHeartbeat), 3.0f);
        bRet = true;
        s_netLogic = this;
    }while(0);
    return bRet;
}

NetLogic* NetLogic::getInstance()
{
    if (!s_netLogic)
    {
        s_netLogic = new NetLogic();
    }
    return s_netLogic;
}


void NetLogic::sendLogic(float dt)
{
//    CCLOG("121212121212");
    if(CommonCommand::getInstance()->isConnected())
        SendNetWork::getInstance()->DealNetWorkThread();
}

void NetLogic::sendHeartbeat(float dt)
{
//    CCLOG("this is my heartbeat");
}

void NetLogic::reciveLogic()
{
    
}

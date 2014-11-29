//
//  ResponseRoomList.cpp
//  Mahjong
//
//  Created by tiki on 14/11/27.
//
//

#include "ResponseRoomList.h"

void ResponseRoomList::DealResponseCommand(HMessage *mess)
{
    int lengh = mess->getInt();
    CCLOG("lengh------>%d",lengh);
    for(int i = 0; i < lengh; i ++)
    {
        int roomId = mess->getInt();
        CCLOG("roomId------->%d", roomId);
        std::string roomName = mess->getUTF8();
        CCLOG("roomName----->%s", roomName.c_str());
        long baseMoney = mess->getLong();
        CCLOG("baseMoney---->%ld", baseMoney);
        long minMoney = mess->getLong();
        CCLOG("minMoney----->%ld", minMoney);
        long maxMoney = mess->getLong();
        CCLOG("maxMoney------>%ld",maxMoney);
        int level = mess->getInt();
        CCLOG("level--------->%d",level);
        int playerNum = mess->getInt();
        CCLOG("player-------->%d",playerNum);
    }

}
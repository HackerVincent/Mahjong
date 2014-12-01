//
//  ResponseTable.cpp
//  Mahjong
//
//  Created by tiki on 14/11/27.
//
//

#include "ResponseTable.h"
#include "Net/data/NetData.h"

void ResponseTable::DealResponseCommand(HMessage *mess)
{
    int tableId = mess->getInt();
    CCLOG("tableId------>%d", tableId);
    std::string tableName = mess->getUTF8();
    CCLOG("tableName---->%s",tableName.c_str());
    int tableState = mess->getInt();
    CCLOG("tabelState--->%d",tableState);
    // 如果tableState是空闲或者等待准备状态
    if(tableState == NetData::TABLE_STATE_IDLE || tableState == NetData::TABLE_STATE_WAIT_READY)
    {
        int tableCount = mess->getInt();
        int seatId = mess->getInt();
        int id = mess->getInt();
        std::string nickName = mess->getUTF8();
        int iconType = mess->getInt();
        std::string icon = mess->getUTF8();
        // 等待准备状态
        if(tableState == 1)
        {
            int readyTime = mess->getInt();
        }
        CCLOG("kong xian ~~");
    }
    // 如果tableState是游戏状态
    if(tableState == NetData::TABLE_STATE_GAMING)
    {
        int count = mess->getInt();
        int seatId = mess->getInt();
        int id = mess->getInt();
        std::string nickName = mess->getUTF8();
        int iconType = mess->getInt();
        std::string icon = mess->getUTF8();
        int gameState = mess->getInt();
        // 如果是等待加状态
        if(gameState == 1)
        {
            for(int i = 0; i < 3; i ++)
            {
                int seatId = mess->getInt();
                // -1 还未选择，0：不加倍，>0 加倍数
                int doubleCt = mess->getInt();
            }
        }
    }
}
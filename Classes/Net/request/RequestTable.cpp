//
//  RequestTable.cpp
//  Mahjong
//  进入房间（桌子）
//  Created by tiki on 14/11/23.
//
//

#include "RequestTable.h"
#include "Net/data/NetData.h"
#include "Net/command/CommonCommand.h"

void RequestTable::CreatBodyPack(HMessage *mes)
{
    CommonCommand::getInstance()->commondID = NetData::CHANNEL_ID_ENTER_ROOM;
    mes->putInt(0);
}
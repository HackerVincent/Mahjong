//
//  RequestRoomList.cpp
//  Mahjong
//
//  Created by tiki on 14/11/23.
//
//

#include "RequestRoomList.h"
#include "Net/data/NetData.h"
#include "Net/command/CommonCommand.h"

void RequestRoomList::CreatBodyPack(HMessage *mes)
{
    CommonCommand::getInstance()->commondID = NetData::CHANNEL_ID_ROOM_LIST;
}
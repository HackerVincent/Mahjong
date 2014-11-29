//
//  RequestExitRoom.cpp
//  Mahjong
//
//  Created by tiki on 14/11/29.
//
//

#include "RequestExitRoom.h"
#include "Net/data/NetData.h"
#include "Net/command/CommonCommand.h"

void RequestExitRoom::CreatBodyPack(HMessage *mes)
{
    CommonCommand::getInstance()->commondID = NetData::CHANNEL_ID_EXIT_ROOM;
}
//
//  RequestReadyClick.cpp
//  Mahjong
//
//  Created by tiki on 14/11/29.
//
//

#include "RequestReadyClick.h"
#include "Net/data/NetData.h"
#include "Net/command/CommonCommand.h"

void RequestReadyClick::CreatBodyPack(HMessage *mes)
{
    CommonCommand::getInstance()->commondID = NetData::CHANNEL_ID_CLICK_READY;
}
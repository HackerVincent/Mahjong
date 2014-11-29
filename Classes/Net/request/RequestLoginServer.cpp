//
//  RequestTest.cpp
//  Mahjong
//
//  Created by tiki on 14/11/2.
//
//

#include "RequestLoginServer.h"
#include "Net/data/NetData.h"
#include "Net/command/CommonCommand.h"

void RequestLoginServer::CreatBodyPack(HMessage *mes)
{
    CommonCommand::getInstance()->commondID = NetData::CHANNEL_ID_LOGIN_SERVER;
}
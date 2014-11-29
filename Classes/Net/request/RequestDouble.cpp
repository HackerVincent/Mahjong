//
//  RequestDouble.cpp
//  Mahjong
//
//  Created by tiki on 14/11/29.
//
//

#include "RequestDouble.h"
#include "Net/data/NetData.h"
#include "Net/command/CommonCommand.h"

void RequestDouble::CreatBodyPack(HMessage *mes)
{
    CommonCommand::getInstance()->commondID = NetData::CHANNEL_ID_DOUBLE;
    // uuid
    mes->putUTF8("uuid");
    // 座位id
    mes->putInt(1);
    // 加倍倍数
    mes->putInt(2);
}
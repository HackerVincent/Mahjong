//
//  RequestPutCard.cpp
//  Mahjong
//
//  Created by tiki on 14/11/30.
//
//

#include "RequestPutCard.h"
#include "Net/data/NetData.h"
#include "Net/command/CommonCommand.h"
#include "GameDate/GameData.h"

void RequestPutCard::CreatBodyPack(HMessage *mes)
{
    CommonCommand::getInstance()->commondID = NetData::CHANNEL_ID_PUT_CARD;
    // uuid
    mes->putUTF8("uuid");
    // 座位id
    mes->putInt(1);
    // cardIndex
    mes->putInt(2);
}
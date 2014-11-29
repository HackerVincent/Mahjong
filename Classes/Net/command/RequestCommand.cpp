//
//  RequestCommand.cpp
//  Mahjong
//
//  Created by tiki on 14/10/29.
//
//

#include "RequestCommand.h"
#include "Net/data/NetData.h"
RequestCommand::RequestCommand()
:mes(NULL)
{
    NetData::isLock = true;
}

RequestCommand::~RequestCommand()
{
    mes = NULL;
}
HMessage* RequestCommand::CreatCmdPacket(){
    mes = new HMessage();
//    mes->put(1);
//    mes->putInt(atol(GameData::getInstance()->getServerInstaneId().c_str()));//参数
//    mes->putInt(1111);
//    mes->putLong(GameData::getInstance()->getID());//服务器获取
    CreatBodyPack(mes);
    return mes;
}
void RequestCommand::CreatBodyPack(HMessage* mes){
    
}
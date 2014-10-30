//
//  RequestCommand.h
//  Mahjong
//
//  Created by tiki on 14/10/29.
//
//

#ifndef __Mahjong__RequestCommand__
#define __Mahjong__RequestCommand__

#include <stdio.h>
#include "Tools/HMessage.h"
class RequestCommand{
    public :
    RequestCommand();
    ~RequestCommand();
    HMessage* mes;
    HMessage* CreatCmdPacket();
    virtual void CreatBodyPack(HMessage* mes);
};

#endif /* defined(__Mahjong__RequestCommand__) */

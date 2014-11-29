//
//  RequestExitRoom.h
//  Mahjong
//  请求退出房间
//  Created by tiki on 14/11/29.
//
//

#ifndef __Mahjong__RequestExitRoom__
#define __Mahjong__RequestExitRoom__

#include <stdio.h>
#include "RequestCommand.h"
#include "Tools/HMessage.h"

class RequestExitRoom : public RequestCommand
{
public:
    virtual void CreatBodyPack(HMessage* mes);
};
#endif /* defined(__Mahjong__RequestExitRoom__) */

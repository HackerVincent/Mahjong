//
//  RequestDouble.h
//  Mahjong
//  加倍
//  Created by tiki on 14/11/29.
//
//

#ifndef __Mahjong__RequestDouble__
#define __Mahjong__RequestDouble__

#include <stdio.h>
#include "RequestCommand.h"
#include "Tools/HMessage.h"

class RequestDouble : public RequestCommand
{
public:
    virtual void CreatBodyPack(HMessage* mes);
};
#endif /* defined(__Mahjong__RequestDouble__) */

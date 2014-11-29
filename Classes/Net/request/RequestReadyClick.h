//
//  RequestReadyClick.h
//  Mahjong
//  点击准备
//  Created by tiki on 14/11/29.
//
//

#ifndef __Mahjong__RequestReadyClick__
#define __Mahjong__RequestReadyClick__

#include <stdio.h>
#include "RequestCommand.h"
#include "Tools/HMessage.h"

class RequestReadyClick : public RequestCommand
{
public:
    virtual void CreatBodyPack(HMessage* mes);
};
#endif /* defined(__Mahjong__RequestReadyClick__) */

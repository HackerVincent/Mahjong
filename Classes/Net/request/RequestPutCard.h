//
//  RequestPutCard.h
//  Mahjong
//
//  Created by tiki on 14/11/30.
//
//

#ifndef __Mahjong__RequestPutCard__
#define __Mahjong__RequestPutCard__

#include <stdio.h>
#include "RequestCommand.h"
#include "Tools/HMessage.h"

class RequestPutCard : public RequestCommand
{
public:
    virtual void CreatBodyPack(HMessage* mes);
};

#endif /* defined(__Mahjong__RequestPutCard__) */

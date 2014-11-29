//
//  ResponsePutCard.h
//  Mahjong
//
//  Created by tiki on 14/11/29.
//
//

#ifndef __Mahjong__ResponsePutCard__
#define __Mahjong__ResponsePutCard__

#include <stdio.h>
#include "Net/command/ResponseCommand.h"
#include "Tools/HMessage.h"

class ResponsePutCard : public ResponseCommand
{
public:
    virtual void DealResponseCommand(HMessage* mes);
};
#endif /* defined(__Mahjong__ResponsePutCard__) */

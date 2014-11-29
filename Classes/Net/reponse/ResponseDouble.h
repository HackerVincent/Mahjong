//
//  ResponseDouble.h
//  Mahjong
//  加倍
//  Created by tiki on 14/11/29.
//
//

#ifndef __Mahjong__ResponseDouble__
#define __Mahjong__ResponseDouble__

#include <stdio.h>
#include "Net/command/ResponseCommand.h"
#include "Tools/HMessage.h"

class ResponseDouble : public ResponseCommand
{
public:
    virtual void DealResponseCommand(HMessage* mes);
};
#endif /* defined(__Mahjong__ResponseDouble__) */

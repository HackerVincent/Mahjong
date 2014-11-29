//
//  ResponseReadyClick.h
//  Mahjong
//  点击准备
//  Created by tiki on 14/11/29.
//
//

#ifndef __Mahjong__ResponseReadyClick__
#define __Mahjong__ResponseReadyClick__

#include <stdio.h>
#include "Net/command/ResponseCommand.h"
#include "Tools/HMessage.h"

class ResponseReadyClick: public ResponseCommand
{
public:
    virtual void DealResponseCommand(HMessage* mes);
};
#endif /* defined(__Mahjong__ResponseReadyClick__) */

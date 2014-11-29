//
//  ResponseExitRoom.h
//  Mahjong
//  请求退出房间
//  Created by tiki on 14/11/29.
//
//

#ifndef __Mahjong__ResponseExitRoom__
#define __Mahjong__ResponseExitRoom__

#include <stdio.h>
#include "Net/command/ResponseCommand.h"
#include "Tools/HMessage.h"

class ResponseExitRoom : public ResponseCommand
{
public:
    virtual void DealResponseCommand(HMessage* mes);
};
#endif /* defined(__Mahjong__ResponseExitRoom__) */

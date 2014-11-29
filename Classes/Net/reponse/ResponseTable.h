//
//  ResponseTable.h
//  Mahjong
//  进入房间（桌子）
//  Created by tiki on 14/11/27.
//
//

#ifndef __Mahjong__ResponseTable__
#define __Mahjong__ResponseTable__

#include <stdio.h>
#include "Net/command/ResponseCommand.h"
#include "Tools/HMessage.h"

class ResponseTable : public ResponseCommand
{
public:
    virtual void DealResponseCommand(HMessage* mes);
};
#endif /* defined(__Mahjong__ResponseTable__) */

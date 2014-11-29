//
//  ResponseTableInfo.h
//  Mahjong
//  桌子所有信息
//  Created by tiki on 14/11/29.
//
//

#ifndef __Mahjong__ResponseTableInfo__
#define __Mahjong__ResponseTableInfo__

#include <stdio.h>
#include "Net/command/ResponseCommand.h"
#include "Tools/HMessage.h"

class ResponseTableInfo : public ResponseCommand
{
public:
    virtual void DealResponseCommand(HMessage* mes);
};
#endif /* defined(__Mahjong__ResponseTableInfo__) */

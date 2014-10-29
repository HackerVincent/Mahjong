//
//  ResponseCommand.h
//  Mahjong
//
//  Created by tiki on 14/10/29.
//
//

#ifndef __Mahjong__ResponseCommand__
#define __Mahjong__ResponseCommand__

#include <stdio.h>
#include "HMessage.h"
class ResponseCommand{
    public :
    virtual void DealResponseCommand(HMessage* mes);
};
#endif /* defined(__Mahjong__ResponseCommand__) */

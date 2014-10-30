//
//  ModelEnter.h
//  Mahjong
//
//  Created by tiki on 14/10/29.
//
//

#ifndef __Mahjong__ModelEnter__
#define __Mahjong__ModelEnter__

#include <stdio.h>
#include "Tools/HMessage.h"
class ModelEnter{
public:
    ModelEnter();
    void DealResponseCommand(HMessage* mes);
};
#endif /* defined(__Mahjong__ModelEnter__) */

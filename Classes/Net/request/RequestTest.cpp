//
//  RequestTest.cpp
//  Mahjong
//
//  Created by tiki on 14/11/2.
//
//

#include "RequestTest.h"
#include "Net/data/NetData.h"

void RequestTest::CreatBodyPack(HMessage *mes)
{
    mes->putInt(111);
}
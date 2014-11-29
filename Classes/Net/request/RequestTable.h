//
//  RequestTable.h
//  Mahjong
//  
//  Created by tiki on 14/11/23.
//
//

#ifndef __Mahjong__RequestTable__
#define __Mahjong__RequestTable__

#include <stdio.h>
#include "RequestCommand.h"
#include "Tools/HMessage.h"

class RequestTable : public RequestCommand
{
public:
    virtual void CreatBodyPack(HMessage* mes);
};
#endif /* defined(__Mahjong__RequestTable__) */

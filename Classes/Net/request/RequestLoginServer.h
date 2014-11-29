//
//  RequestTest.h
//  Mahjong
//  登陆服务器
//  Created by tiki on 14/11/2.
//
//

#ifndef __Mahjong__RequestTest__
#define __Mahjong__RequestTest__

#include <stdio.h>
#include "RequestCommand.h"
#include "Tools/HMessage.h"

class RequestLoginServer : public RequestCommand
{
public:
    virtual void CreatBodyPack(HMessage* mes);
};

#endif /* defined(__Mahjong__RequestTest__) */

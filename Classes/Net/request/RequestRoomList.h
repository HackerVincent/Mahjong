//
//  RequestRoomList.h
//  Mahjong
//  请求房间列表
//  Created by tiki on 14/11/23.
//
//

#ifndef __Mahjong__RequestRoomList__
#define __Mahjong__RequestRoomList__

#include <stdio.h>
#include "RequestCommand.h"
#include "Tools/HMessage.h"

class RequestRoomList : public RequestCommand
{
public:
    virtual void CreatBodyPack(HMessage* mes);
};


#endif /* defined(__Mahjong__RequestRoomList__) */

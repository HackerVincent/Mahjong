//
//  ResponseRoomList.h
//  Mahjong
//  请求房间列表
//  Created by tiki on 14/11/27.
//
//

#ifndef __Mahjong__ResponseRoomList__
#define __Mahjong__ResponseRoomList__

#include <stdio.h>
#include "Net/command/ResponseCommand.h"
#include "Tools/HMessage.h"

class ResponseRoomList : public ResponseCommand
{
public:
    virtual void DealResponseCommand(HMessage* mes);
};

#endif /* defined(__Mahjong__ResponseRoomList__) */

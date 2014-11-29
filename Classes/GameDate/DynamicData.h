//
//  DynamicData.h
//  Mahjong
//
//  Created by tiki on 14/11/26.
//
//

#ifndef __Mahjong__DynamicData__
#define __Mahjong__DynamicData__

#include <stdio.h>
#include "cocos2d.h"
class DynamicData
{
public:
    DynamicData(){
        s_dynamic = nullptr;
        _roomId = -1;
    };
    ~DynamicData(){};
    
    static DynamicData* getInstance();
    static DynamicData* s_dynamic;
    
private:
    // 当前房间号
    CC_SYNTHESIZE(int , _roomId, RoomId);
};

#endif /* defined(__Mahjong__DynamicData__) */

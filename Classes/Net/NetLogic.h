//
//  NetLogic.h
//  Mahjong
//  代替线程处理网络逻辑----用单例
//  Created by tiki on 14/10/30.
//
//

#ifndef __Mahjong__NetLogic__
#define __Mahjong__NetLogic__

#include <stdio.h>
#include "cocos2d.h"

class NetLogic : public cocos2d::Node
{
public:
    NetLogic();
    virtual ~NetLogic();
    void onEnter();
    bool init();
    static NetLogic* getInstance();
    CREATE_FUNC(NetLogic);
private:
    void sendLogic(float dt);
    
};

#endif /* defined(__Mahjong__NetLogic__) */

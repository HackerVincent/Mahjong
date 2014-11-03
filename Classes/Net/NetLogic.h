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
    void onExit();
    bool init();
    static NetLogic* getInstance();
    CREATE_FUNC(NetLogic);
private:
    // 发送消息
    void sendLogic(float dt);
    // 发送心跳
    void sendHeartbeat(float dt);
    // 接受消息
    void reciveLogic();
};

#endif /* defined(__Mahjong__NetLogic__) */

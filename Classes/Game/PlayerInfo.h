//
//  PlayerInfo.h
//  Mahjong
//  牌桌上玩家信息
//  Created by tiki on 14/11/22.
//
//

#ifndef __Mahjong__PlayerInfo__
#define __Mahjong__PlayerInfo__

#include <stdio.h>
#include "cocos2d.h"
#include "Game/Card.h"

class PlayerInfo : public cocos2d::Ref
{
public:
    PlayerInfo();
    ~PlayerInfo();
    void setPlayerCards(int* cardTiles);
private:
    std::vector<Card*> _cards;
};

#endif /* defined(__Mahjong__PlayerInfo__) */

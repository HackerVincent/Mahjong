//
//  Card.h
//  Mahjong
//  牌
//  Created by tiki on 14/11/22.
//
//

#ifndef __Mahjong__Card__
#define __Mahjong__Card__

#include <stdio.h>
#include "cocos2d.h"

class Card : public cocos2d::Sprite
{
public:
    Card();
    ~Card();
    bool init();
    // 根据花色创建牌
    void createWithTile(int tile);
    CREATE_FUNC(Card);
private:
    // 花色
    CC_SYNTHESIZE(int, _tile, Tile);
    // 是否可触摸
    CC_SYNTHESIZE(bool, _canTouch, CanTouch);
    // 判断是否可触摸
    bool onTouchBegan(cocos2d::Touch* touch, cocos2d::Event  *event);
    
    
    // 牌的类型
    CC_SYNTHESIZE(int, _type, Type);
    // 牌的值
    CC_SYNTHESIZE(int, _vaule, Value);
    // 牌的索引
    CC_SYNTHESIZE(int, _index, Index);
};

#endif /* defined(__Mahjong__Card__) */

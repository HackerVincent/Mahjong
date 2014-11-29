//
//  Card.cpp
//  Mahjong
//
//  Created by tiki on 14/11/22.
//
//

#include "Card.h"
using namespace cocos2d;

Card::Card()
:_canTouch(true)
,_tile(0)
,_type(0)
,_vaule(0)
,_index(0)
{
    
}

Card::~Card()
{
    
}

void Card::createWithTile(int tile)
{
    setTile(tile);
    char buffer[128];
    sprintf(buffer, "GameTile/Tile%d.png", getTile());
    initWithFile(buffer);
}

bool Card::init()
{
    bool bRet = false;
    do{
        CC_BREAK_IF( !Sprite::init());
        auto listener = EventListenerTouchOneByOne::create();
        listener->onTouchBegan = CC_CALLBACK_2(Card::onTouchBegan, this);
        _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

        bRet = true;
    }while(0);
    return bRet;
    
}

bool Card::onTouchBegan(cocos2d::Touch *touch, cocos2d::Event *event)
{
    auto target = static_cast<Sprite*>(event->getCurrentTarget());//获取的当前触摸的目标
    Point locationInNode = target->convertToNodeSpace(touch->getLocation());
    Size s = target->getContentSize();
    Rect rect = Rect(0, 0, s.width, s.height);
    if (rect.containsPoint(locationInNode) && getCanTouch())//判断触摸点是否在目标的范围内
    {
        CCLOG("big~~~~~~");
        return true;
    }
    else
    {
        return false;
    }
}

//
//  GameData.cpp
//  HeroRunRunRunNew
//
//  Created by tiki on 14-10-14.
//
//

#include "GameData.h"
#include "cocos2d.h"

static GameData* s_gameData = nullptr;

GameData::GameData()
{
   
}

GameData::~GameData()
{
    s_gameData = nullptr;
}

GameData* GameData::getInstance()
{
    if (!s_gameData)
    {
        s_gameData = new GameData();
    }
    return s_gameData;
}

void GameData::save()
{
    cocos2d::UserDefault* userDefault = cocos2d::UserDefault::getInstance();
//    userDefault->setIntegerForKey("test", _test);
//    userDefault->setBoolForKey("hasBuy", _hasBuy);
    
    
    userDefault->flush();
}

void GameData::load()
{
    cocos2d::UserDefault *userDefault = cocos2d::UserDefault::getInstance();
    if(!userDefault->getBoolForKey("isHaveSaveFile"))
    {
        userDefault->setBoolForKey("isHaveSaveFile", true);
        save();
        userDefault->flush();
        
        return;
    }
//    _test = userDefault->getIntegerForKey("CurRole", 0);
}
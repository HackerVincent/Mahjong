//
//  UI_Login.cpp
//  Mahjong
//
//  Created by tiki on 14/10/27.
//
//

#include "UI_Login.h"
using namespace cocos2d;

UI_Login::UI_Login()
{
    
}

UI_Login::~UI_Login()
{
    
}

Scene* UI_Login::scene()
{
    auto scene = Scene::create();
    auto layer = UI_Login::create();
    scene->addChild(layer);
    return scene;
}

bool UI_Login::init()
{
    bool bRet = false;
    do{
        CC_BREAK_IF( !Layer::init());
        bRet =true;
    }while(0);
    return bRet;
}
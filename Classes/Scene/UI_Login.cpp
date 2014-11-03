//
//  UI_Login.cpp
//  Mahjong
//
//  Created by tiki on 14/10/27.
//
//

#include "UI_Login.h"
#include "HelloWorldScene.h"
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
        Size visibleSize = Director::getInstance()->getVisibleSize();
        Vec2 origin = Director::getInstance()->getVisibleOrigin();
        auto closeItem = MenuItemImage::create(
                                               "CloseNormal.png",
                                               "CloseSelected.png",
                                               CC_CALLBACK_1(UI_Login::menuCloseCallback, this));
        
        closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                    origin.y + closeItem->getContentSize().height/2));

        
        auto menu = Menu::create(closeItem,NULL);
        menu->setPosition(Vec2::ZERO);
        this->addChild(menu, 1);
        bRet =true;
    }while(0);
    return bRet;
}

void UI_Login::menuCloseCallback(cocos2d::Ref *pSender)
{
    Director::getInstance()->replaceScene(HelloWorld::createScene());
}
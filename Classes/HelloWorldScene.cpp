#include "HelloWorldScene.h"
#include "Net/MWebSocket.h"
#include "CommonCommand.h"
USING_NS_CC;

Scene* HelloWorld::createScene()
{
    auto scene = Scene::create();
    auto layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));
    
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2 ,
                                origin.y + closeItem->getContentSize().height/2));


    
    auto label = LabelTTF::create("Hello World", "Arial", 24);
    
    
    auto sendLabel = MenuItemFont::create("Send Text", CC_CALLBACK_0(HelloWorld::send, this));
    sendLabel->setPosition(Vec2(300, 400));
    
    auto menu = Menu::create(closeItem, sendLabel,NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    this->addChild(label, 1);

    auto sprite = Sprite::create("HelloWorld.png");
    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
    this->addChild(sprite, 0);
    
    
    // 测试游戏会不会因为webSocket而阻塞
    auto test = Sprite::create("CloseNormal.png");
    this->addChild(test);
    test->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    test->runAction(RepeatForever::create(Sequence::create(MoveBy::create(1.0f, Point(100,0)),MoveBy::create(1.0f, Point(-100,0)), NULL)));
    
    
    return true;
}

void HelloWorld::send()
{
//    _socket->send();
    auto mess = new HMessage();
    mess->putUTF8("法克鱿~");
    CommonCommand::getInstance()->sendMessage(mess);
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
//	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
//    return;
//#endif
//
//    Director::getInstance()->end();
//
//#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//    exit(0);
//#endif
    CommonCommand::getInstance()->creatConnection();
}

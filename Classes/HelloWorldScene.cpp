#include "HelloWorldScene.h"
#include "Net/MWebSocket.h"
#include "Net/command/CommonCommand.h"
#include "Scene/UI_Login.h"
#include "Net/command/SendNetWork.h"
#include "Net/request/RequestTest.h"
#include "extensions/cocos-ext.h"
#include "network/HttpClient.h"
#include "Tools/jionsx.h"
#include "GameDate/GameData.h"
USING_NS_CC;
using namespace cocos2d::network;

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


    
    label = LabelTTF::create("Hello World", "Arial", 24);
    
    labelShow = LabelTTF::create("the websocket is not connecting.", "Arial", 24);
    labelShow->setPosition(Vec2(200, 100));
    this->addChild(labelShow);
    
    auto sendLabel = MenuItemFont::create("Send Text", CC_CALLBACK_0(HelloWorld::send, this));
    sendLabel->setPosition(Vec2(300, 400));
    
    auto Http = MenuItemFont::create("Http", CC_CALLBACK_0(HelloWorld::Http, this));
    Http->setPosition(Vec2(300, 300));
    
    auto connetLavbel = MenuItemFont::create("Connet", [](Ref* ref){
        CommonCommand::getInstance()->creatConnection();
    });
    connetLavbel->setPosition(Vec2(500, 400));
    
    auto menu = Menu::create(closeItem, sendLabel, Http, connetLavbel,NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    this->scheduleUpdate();
    
    label->setPosition(Vec2(origin.x + visibleSize.width/2,
                            origin.y + visibleSize.height - label->getContentSize().height));

    this->addChild(label, 1);

//    auto sprite = Sprite::create("HelloWorld.png");
//    sprite->setPosition(Vec2(visibleSize.width/2 + origin.x, visibleSize.height/2 + origin.y));
//    this->addChild(sprite, 0);
    
    // 测试游戏会不会因为webSocket而阻塞
    auto test = Sprite::create("CloseNormal.png");
    this->addChild(test);
    test->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2));
    test->runAction(RepeatForever::create(Sequence::create(MoveBy::create(1.0f, Point(100,0)),MoveBy::create(1.0f, Point(-100,0)), NULL)));
    
    
    return true;
}

void HelloWorld::update(float dt)
{
    if(CommonCommand::getInstance()->isConnected())
    {
        labelShow->setString("The webSocket is connected~");
    }else
    {
        labelShow->setString("The webSocket is not connect.");
    }
}

void HelloWorld::send()
{
//    _socket->send();
    auto mess = new HMessage();
//
    mess->putInt(10);
    mess->putShort(20);
    mess->putLong(12);
    mess->putUTF8("fuck~~~~~~");
//     发送消息
    CommonCommand::getInstance()->sendMessage(mess);
//    SendNetWork::getInstance()->AddNetCommand(new RequestTest());
}

void HelloWorld::Http()
{
    
//    HttpRequest* request = new HttpRequest();
//    request->setUrl("http://httpbin.org/post");
//    request->setRequestType(HttpRequest::Type::POST);
//    request->setResponseCallback(CC_CALLBACK_2(HelloWorld::onHttpRequestCompleted, this));
    
    
    
    HttpRequest* request = new HttpRequest();
    request->setUrl("http://1.93.31.157:8081/GCenter/guestLogin?gameId=20001&channelName=default&os=android&clientId=123&versionCode=1");
    request->setRequestType(HttpRequest::Type::GET);
    request->setResponseCallback(CC_CALLBACK_2(HelloWorld::onHttpRequestCompleted, this));
//    if (isImmediate)
//    {
//        request->setTag("GET immediate test1");
        HttpClient::getInstance()->sendImmediate(request);
//    }else
//    {
        request->setTag("guestLogin");
//        HttpClient::getInstance()->send(request);
//    }
    request->release();
    
    
//    // write the post data
//    char postData[22] = "binary=hello\0\0cocos2d";  // including \0, the strings after \0 should not be cut in response
//    request->setRequestData(postData, 22);
////    if (isImmediate)
////    {
////        request->setTag("POST Binary immediate test");
////        HttpClient::getInstance()->sendImmediate(request);
////    }else
////    {
//        request->setTag("POST Binary test");
//        HttpClient::getInstance()->send(request);
////    }
//    request->release();
}


void HelloWorld::onHttpRequestCompleted(cocos2d::network::HttpClient *sender, cocos2d::network::HttpResponse *response)
{
    if (!response)
    {
        return;
    }
    
    // You can get original request type from: response->request->reqType
    if (0 != strlen(response->getHttpRequest()->getTag()))
    {
        log("%s completed", response->getHttpRequest()->getTag());
    }
    
    long statusCode = response->getResponseCode();
    char statusString[64] = {};
    sprintf(statusString, "HTTP Status Code: %ld, tag = %s", statusCode, response->getHttpRequest()->getTag());
//    _labelStatusCode->setString(statusString);
    log("response code: %ld", statusCode);
    
    if (!response->isSucceed())
    {
        log("response failed");
        log("error buffer: %s", response->getErrorBuffer());
        return;
    }
    
    // dump data
    std::vector<char> *buffer = response->getResponseData();
    printf("Http Test, dump data: ");
    std::string temp_data = "";
    for (unsigned int i = 0; i < buffer->size(); i++)
    {
        temp_data += (*buffer)[i];
        printf("%c", (*buffer)[i]);
    }
    jionsx* temps = new jionsx(temp_data);
    printf("\n");
    
    
    if(response->getHttpRequest()->getTag() == "guestLogin")
    {
        GameData::getInstance()->setID(temps->getStringValue("id"));
        GameData::getInstance()->setUserId(temps->getStringValue("userId"));
        GameData::getInstance()->setUserPass(temps->getStringValue("userPass"));
        GameData::getInstance()->setUserName(temps->getStringValue("userName"));
        GameData::getInstance()->setIconType(temps->getIntValue("iconType"));
        GameData::getInstance()->setSex(temps->getIntValue("sex"));
        GameData::getInstance()->setSkey(temps->getStringValue("skey"));
        GameData::getInstance()->setIP(temps->getStringValue("ip"));
        GameData::getInstance()->setPort(temps->getStringValue("port"));
        GameData::getInstance()->setState(temps->getIntValue("state"));
        GameData::getInstance()->setUpdate(temps->getIntValue("update"));
        GameData::getInstance()->setDownUrl(temps->getStringValue("downUrl"));
        
        CCLOG("user------>%s", temps->getStringValue("userId").c_str());
//        int id_temp = temps->getIntValue("update");
        
    }
    
    if (0 != strlen(response->getHttpRequest()->getTag()))
    {
        log("%s completed", response->getHttpRequest()->getTag());
    }
    
    
    if (response->getHttpRequest()->getReferenceCount() != 2)
    {
        log("request ref count not 2, is %d", response->getHttpRequest()->getReferenceCount());
    }
}

void HelloWorld::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
//    Director::getInstance()->replaceScene(UI_Login::scene());
}

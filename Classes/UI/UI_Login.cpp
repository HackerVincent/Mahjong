//
//  UI_Login.cpp
//  Mahjong
//
//  Created by tiki on 14/11/20.
//
//

#include "UI_Login.h"
#include "GameDate/GameData.h"
#include "Tools/jionsx.h"
#include "UI/UI_Hall.h"
#include "HelloWorldScene.h"
#include "Net/command/CommonCommand.h"
using namespace cocostudio;
using namespace std;
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
        auto layout = dynamic_cast<Layout*>(GUIReader::getInstance()->widgetFromJsonFile("UI/UI_Login.json"));
        addChild(layout);
        // 游客登陆
        auto btn_next = dynamic_cast<Button*>(Helper::seekWidgetByName(layout, "btn_guest"));
        btn_next->addTouchEventListener(CC_CALLBACK_2(UI_Login::guestLogin,this ));

        bRet = true;
    }while(0);
    return bRet;
}

void UI_Login::guestLogin(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
    switch (type) {
        case Widget::TouchEventType::BEGAN:
        {
            
        }
            break;
        case Widget::TouchEventType::ENDED:
        {
//            HttpRequest* request = new HttpRequest();
//            request->setUrl("http://192.168.1.113:8081/GCenter/guestLogin?gameId=20001&channelName=default&os=android&clientId=123&versionCode=1");
//            request->setRequestType(HttpRequest::Type::GET);
//            request->setResponseCallback(CC_CALLBACK_2(UI_Login::onHttpRequestCompleted, this));
//            HttpClient::getInstance()->sendImmediate(request);
//            request->setTag(GUEST_LOGIN);
//            request->release();
            auto scene = UI_Hall::scene();
            Director::getInstance()->replaceScene(scene);
        }
            break;
        default:
            break;
    }
}

void UI_Login::onHttpRequestCompleted(cocos2d::network::HttpClient *sender, cocos2d::network::HttpResponse *response)
{
    if (!response)
    {
        return;
    }
    
    if (0 != strlen(response->getHttpRequest()->getTag()))
    {
        log("%s completed", response->getHttpRequest()->getTag());
    }
    
    long statusCode = response->getResponseCode();
    char statusString[64] = {};
    sprintf(statusString, "HTTP Status Code: %ld, tag = %s", statusCode, response->getHttpRequest()->getTag());
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
//    printf("\n");
    
    string requestTag = response->getHttpRequest()->getTag();
    CCLOG("requestTag-------->%s",requestTag.c_str());
    if(requestTag.compare(GUEST_LOGIN) == 0)
    {
        GameData::getInstance()->setID(temps->getIntValue("id"));
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
    }
    
    if (0 != strlen(response->getHttpRequest()->getTag()))
    {
        log("%s completed", response->getHttpRequest()->getTag());
    }
    
    
    if (response->getHttpRequest()->getReferenceCount() != 2)
    {
        log("request ref count not 2, is %d", response->getHttpRequest()->getReferenceCount());
    }
    // 建立socket连接
    CommonCommand::getInstance()->creatConnection();
    
    
    
//    auto scene = HelloWorld::createScene();
    auto scene = UI_Hall::scene();
    Director::getInstance()->replaceScene(scene);
}

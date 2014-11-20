//
//  UI_Login.h
//  Mahjong
//  登陆界面
//  Created by tiki on 14/11/20.
//
//

#ifndef __Mahjong__UI_Login__
#define __Mahjong__UI_Login__

#include <stdio.h>
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "network/HttpClient.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;
using namespace cocos2d::network;

#define GUEST_LOGIN "guestLogin"

class UI_Login : public cocos2d::Layer
{
public:
    UI_Login();
    virtual ~UI_Login();
    static cocos2d::Scene* scene();
    bool init();
    CREATE_FUNC(UI_Login);
protected:
    // 游客登陆
    void guestLogin(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    //
    void onHttpRequestCompleted(HttpClient *sender, HttpResponse *response);
};

#endif /* defined(__Mahjong__UI_Login__) */

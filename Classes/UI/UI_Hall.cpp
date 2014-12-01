//
//  UI_Hall.cpp
//  Mahjong
//
//  Created by tiki on 14/11/22.
//
//

#include "UI_Hall.h"
#include "UI/UI_Tabel.h"
#include "GameDate/GameData.h"
#include "Net/command/SendNetWork.h"
#include "Net/request/RequestLoginServer.h"
#include "Net/request/RequestTable.h"
#include "Net/request/RequestRoomList.h"
#include "GameDate/DynamicData.h"

UI_Hall::UI_Hall()
{
    
}

UI_Hall::~UI_Hall()
{
    
}

Scene* UI_Hall::scene()
{
    auto scene = Scene::create();
    auto layer = UI_Hall::create();
    scene->addChild(layer);
    return scene;
}

bool UI_Hall::init()
{
    bool bRet = false;
    do{
        CC_BREAK_IF(!Layer::init());
        auto layout = dynamic_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("UI/UI_Hall.json"));
        addChild(layout);
        // 游客登陆
        auto btn_game1 = dynamic_cast<Button*>(Helper::seekWidgetByName(layout, "btn_game1"));
        btn_game1->addTouchEventListener(CC_CALLBACK_2(UI_Hall::gameEnter,this ));
        // 大房间
        _layout_bigRoom = dynamic_cast<Layout*>(Helper::seekWidgetByName(layout, "panel_bigRoomSelect"));
        // 小房间
        _layout_samllRoom = dynamic_cast<Layout*>(Helper::seekWidgetByName(layout, "panel_roomSelect"));
        // 返回按钮
        _btnBack = dynamic_cast<Button*>(Helper::seekWidgetByName(layout, "btn_back"));
        _btnBack->addTouchEventListener(CC_CALLBACK_2(UI_Hall::changeRoom,this ));
        _btnBack->setTouchEnabled(false);
        _btnBack->setVisible(false);
        // 头像
        _imgPortrait = dynamic_cast<ImageView*>(Helper::seekWidgetByName(layout, "img_portrait"));
        
        //
        auto btn_enterRoom1 = dynamic_cast<Button*>(Helper::seekWidgetByName(layout, "btn_room1"));
        btn_enterRoom1->addTouchEventListener(CC_CALLBACK_2(UI_Hall::roomEnter,this ));
        btn_enterRoom1->setTag(10001);
        
        
        
        SendNetWork::getInstance()->AddNetCommand(new RequestLoginServer());
        
        // 用户名
//        auto label_name = dynamic_cast<Label*>(Helper::seekWidgetByName(layout, "label_name"));
//        label_name->setString(GameData::getInstance()->getUserName());
        
        bRet = true;
    }while(0);
    return bRet;
}

void UI_Hall::roomEnter(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
    auto button = dynamic_cast<Button*>(pSender);
    int roomId = button->getTag() - 10000;
    DynamicData::getInstance()->setRoomId(roomId);
    switch (type) {
        case Widget::TouchEventType::BEGAN:
        {
            
        }
            break;
        case Widget::TouchEventType::ENDED:
        {
            auto scene = UI_Table::scene();
            Director::getInstance()->replaceScene(scene);
            SendNetWork::getInstance()->AddNetCommand(new RequestTable());
        }
            break;
        default:
            break;
    }
}

void UI_Hall::gameEnter(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
    switch (type) {
        case Widget::TouchEventType::BEGAN:
        {
            
        }
            break;
        case Widget::TouchEventType::ENDED:
        {
            _layout_bigRoom->setVisible(false);
            _layout_bigRoom->setTouchEnabled(false);
            _imgPortrait->setVisible(false);
            _layout_samllRoom->setVisible(true);
            _layout_samllRoom->setTouchEnabled(true);
            _btnBack->setTouchEnabled(true);
            _btnBack->setVisible(true);
            SendNetWork::getInstance()->AddNetCommand(new RequestRoomList());
        }
            break;
        default:
            break;
    }
}

void UI_Hall::changeRoom(cocos2d::Ref *pSender, cocos2d::ui::Widget::TouchEventType type)
{
    switch (type) {
        case Widget::TouchEventType::BEGAN:
        {
            
        }
            break;
        case Widget::TouchEventType::ENDED:
        {
            _layout_bigRoom->setVisible(true);
            _layout_bigRoom->setTouchEnabled(true);
            _imgPortrait->setVisible(true);
            _layout_samllRoom->setVisible(false);
            _layout_samllRoom->setTouchEnabled(false);
            _btnBack->setTouchEnabled(false);
            _btnBack->setVisible(false);
        }
            break;
        default:
            break;
    }
}
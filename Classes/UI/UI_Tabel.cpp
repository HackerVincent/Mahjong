//
//  UI_Tabel.cpp
//  Mahjong
//
//  Created by tiki on 14/11/22.
//
//

#include "UI_Tabel.h"
#include "Game/Card.h"
#include "Net/request/RequestExitRoom.h"
#include "Net/command/SendNetWork.h"
#include "Net/request/RequestReadyClick.h"
#include "UI/UI_Hall.h"

UI_Table::UI_Table()
:_timeDownStartNum(0)
,_playerIding(0)
{
    memset(_imgTime, 0, sizeof(_imgTime));
    memset(_labelATime, 0, sizeof(_labelATime));
}

UI_Table::~UI_Table()
{
    
}

Scene* UI_Table::scene()
{
    auto scene = Scene::create();
    auto layer = UI_Table::create();
    scene->addChild(layer);
    return scene;
}

bool UI_Table::init()
{
    bool bRet = false;
    do{
        CC_BREAK_IF(!Layer::init());
        auto layout = dynamic_cast<Layout*>(cocostudio::GUIReader::getInstance()->widgetFromJsonFile("UI/UI_Table.json"));
        addChild(layout);
        char buffer[64];
        for(int i = 0; i < 3; i ++)
        {
            sprintf(buffer, "img_timer%d", i + 1);
            _imgTime[i] = dynamic_cast<ImageView*>(Helper::seekWidgetByName(layout, buffer));
            _imgTime[i]->setVisible(false);
            
            sprintf(buffer, "labelA_%d", i + 1);
            _labelATime[i] = dynamic_cast<TextAtlas*>(Helper::seekWidgetByName(layout, buffer));
            _labelATime[i]->setVisible(true);
        }
        
        startTimeDown(1,10);
        
        bRet = true;
        
        for(int i = 0 ; i < 13; i ++)
        {
            auto card = Card::create();
            card->createWithTile(i);
            card->setScale(0.4f);
            card->setPosition(Vec2(100 + i * 80, 200));
            this->addChild(card);
        }
        
        
        auto ExitLabel = MenuItemFont::create("Exit Room", CC_CALLBACK_0(UI_Table::ExitRoom, this));
        ExitLabel->setPosition(Vec2(300, 400));

        
        auto Ready = MenuItemFont::create("Ready", CC_CALLBACK_0(UI_Table::Ready, this));
        Ready->setPosition(Vec2(300, 500));
        
        auto menu = Menu::create(ExitLabel, Ready,NULL);
        menu->setPosition(Vec2::ZERO);
        this->addChild(menu, 1);
        
    }while(0);
    return bRet;
}

void UI_Table::ExitRoom()
{
    SendNetWork::getInstance()->AddNetCommand(new RequestExitRoom());
    auto scene = UI_Hall::scene();
    Director::getInstance()->replaceScene(scene);
}

void UI_Table::Ready()
{
    SendNetWork::getInstance()->AddNetCommand(new RequestReadyClick());
}

void UI_Table::startTimeDown(int index, int timeNum)
{
    for(int i = 0; i < 3; i ++)
    {
        _imgTime[i]->setVisible(false);
    }
    _imgTime[index]->setVisible(true);
    _timeDownStartNum = timeNum;
    _playerIding= index;
    char buffer[64];
    sprintf(buffer, "%d",timeNum);
    _labelATime[index]->setString(buffer);
    this->schedule(schedule_selector(UI_Table::TimeDown), 1.0f);
}

void UI_Table::TimeDown(float dt)
{
    if(_timeDownStartNum <= 0)
    {
        this->unschedule(schedule_selector(UI_Table::TimeDown));
        return;
    }
    
    _timeDownStartNum --;
    char buffer[64];
    sprintf(buffer, "%d",_timeDownStartNum);
    _labelATime[_playerIding]->setString(buffer);
}
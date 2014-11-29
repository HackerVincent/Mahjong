//
//  UI_Hall.h
//  Mahjong
//
//  Created by tiki on 14/11/22.
//
//

#ifndef __Mahjong__UI_Hall__
#define __Mahjong__UI_Hall__

#include <stdio.h>
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

class UI_Hall : public cocos2d::Layer
{
public:
    UI_Hall();
    ~UI_Hall();
    static cocos2d::Scene* scene();
    bool init();
    CREATE_FUNC(UI_Hall);
private:
    // 大房间选择界面
    Layout* _layout_bigRoom;
    // 小房间选择界面
    Layout* _layout_samllRoom;
    // 返回按钮
    Button* _btnBack;
    // 头像
    ImageView* _imgPortrait;
    // 进入游戏
    void gameEnter(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    // 切换大小房间选择
    void changeRoom(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
    // 进入房间
    void roomEnter(Ref *pSender, cocos2d::ui::Widget::TouchEventType type);
};



#endif /* defined(__Mahjong__UI_Hall__) */

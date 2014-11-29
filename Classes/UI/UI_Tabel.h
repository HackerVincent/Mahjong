//
//  UI_Tabel.h
//  Mahjong
//
//  Created by tiki on 14/11/22.
//
//

#ifndef __Mahjong__UI_Tabel__
#define __Mahjong__UI_Tabel__

#include <stdio.h>
#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;

class UI_Table : public cocos2d::Layer
{
public:
    UI_Table();
    ~UI_Table();
    static Scene* scene();
    bool init();
    CREATE_FUNC(UI_Table);
private:
    void ExitRoom();
    void Ready();
    // 倒计时起始时间
    int _timeDownStartNum;
    // 哪个玩家正在等待逻辑
    int _playerIding;
    // 倒计时底图
    ImageView* _imgTime[3];
    // 倒计时数字
    TextAtlas* _labelATime[3];
    
protected:
    // 开始倒计时
    void startTimeDown(int index, int timeNum);
    // 三个时钟倒计时
    void TimeDown(float dt);
};


#endif /* defined(__Mahjong__UI_Tabel__) */

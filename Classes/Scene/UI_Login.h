//
//  UI_Login.h
//  Mahjong
//
//  Created by tiki on 14/10/27.
//
//

#ifndef __Mahjong__UI_Login__
#define __Mahjong__UI_Login__

#include <stdio.h>
#include "cocos2d.h"

class UI_Login : public cocos2d::Layer
{
public:
    UI_Login();
    virtual ~UI_Login();
    static cocos2d::Scene* scene();
    bool init();
    CREATE_FUNC(UI_Login);
};


#endif /* defined(__Mahjong__UI_Login__) */

//
//  Data.h
//  Mahjong
//
//  Created by tiki on 14/10/29.
//
//

#ifndef __Mahjong__Data__
#define __Mahjong__Data__

#include <stdio.h>
class NetData{
public:
    static bool isHeartSafe;
    static int HeartCount;
    static int HeartTimeSafe;
    /**********协议号***************/
    enum DealNum
    {
        C_ENTER_GAME = 0x000A0001,//进入游戏
        S_NOREQUEST_RESP = 0x100A0000, //无请求的，服务器主动下发的协议
    };
    /*************模块号*****************/
    enum ModelNum
    {
        MODEL_ID_ENTERGAME = 1,//
        MODEL_ID_SELECTROOM = 2, //
        MODEL_ID_CHAT = 3,//聊天
        MODEL_ID_TIPS = 4,//提示
        MODEL_ID_CARD =5,
        MODEL_ID_UPDATE_CLOCK = 6,
        MODEL_ID_ENTERTABLE = 7,
        MODEL_ID_ENTERTABLE_OTHERS = 8,
        MODEL_ID_READY = 9,
        MODEL_ID_TABLE_INFO = 11,
        MODEL_ID_TASK= 12,
        MODEL_ID_SETTLEMENT = 13,//结算
    };
    static bool isLock;
    static int recordCommonID;
    static int commonIDArray[];
    static bool isHaveCommonID(int commonID);
    static const char THREE_TYPE = 1;//三人斗地主的类型 对应到room.xml中roomType
    //打牌时候的状态
    static const char STAUS_NONE = 0;
    static const char STATUS_NOMAL = 1;//未准备

    static bool isOutLine;
};
#endif /* defined(__Mahjong__Data__) */

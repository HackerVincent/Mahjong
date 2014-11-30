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
//    enum DealNum
//    {
//        C_ENTER_GAME = 0x000A0001,//进入游戏
//        S_NOREQUEST_RESP = 0x100A0000, //无请求的，服务器主动下发的协议
//        PLAYEINFO_ = 50200,
//    };
    /*************协议号*****************/
    enum ChannelId
    {
        CHANNEL_ID_HEART = 10100,             // 心跳
        CHANNEL_ID_LOGIN_SERVER = 10200,      // 登陆游戏服务器
        CHANNEL_ID_ROOM_LIST = 10300,         // 请求房间列表
        CHANNEL_ID_ENTER_ROOM = 10400,        // 进入房间（桌子）
        CHANNEL_ID_EXIT_ROOM = 10500,         // 离开房间（桌子）
        CHANNEL_ID_CLICK_READY = 10600,       // 点击准备
        CHANNEL_ID_DOUBLE = 10700,            // 加倍
        CHANNEL_ID_TABLE_RANDOM_NUM = 10800,  // table随机数收集
        CHANNEL_ID_PUT_CARD = 10900,          // 出牌
    };
    
    /*************模块号*****************/
    enum ModleId
    {
        MODLE_ID_HEART = 50100,             // 心跳
        MODLE_ID_LOGIN_SERVER = 50200,      // 登陆游戏服务器
        MODLE_ID_ROOM_LIST = 50300,         // 请求房间列表
        MODLE_ID_ENTER_ROOM = 50400,        // tableInfo
        MODLE_ID_EXIT_ROOM = 50500,         // 离开房间（桌子）
        MODLE_ID_READY_COUNTDOWN = 50600,   // 提示准备倒计时（主动下发）
        MODLE_ID_KICKOUT_ROOM = 50700,      // 提示被提出桌子（主动下发）
        MODLE_ID_NORMAL_TIPS = 60000,       // 普通提示符（主动下发）
        MODLE_ID_TOP_TIPS = 60100,          // 顶部提示符（主动下发）
        MODLE_ID_ONE_BUTOON_TIPS = 60200,   // 带一个按钮提示符（主动下发）
        MODLE_ID_TWO_BUTTON_TIPS = 60300,   // 带两个按钮提示符（主动下发）
        MODLE_ID_WORLD_TIPS = 60400,        // 世界消息提示（主动下发）
    };
    
    /*************桌子状态*****************/
    enum TableState
    {
        TABLE_STATE_IDLE = 0,               // 空闲
        TABLE_STATE_WAIT_READY = 1,         // 等待准备
        TABLE_STATE_GAMING = 2,             // 游戏中
        TABLE_STATE_END = 3,                // 结束（等同于空闲）
    };
    
    /*************玩家状态*****************/
    enum PalyerState
    {
        PLAYER_STATE_IDLE = 0,               // 空闲(不在房间内)
        PLAYER_STATE_NOT_READY = 1,          // 未准备
        PLAYER_STATE_HAS_READY = 2,          // 已准备
        PLAYER_STATE_INGAME = 3,             // 游戏中
    };
    
    /*************玩家被T类型*****************/
    enum PalyerBeTType
    {
        GAME_KICK_BY_SYS = 0,               // 被系统T
        GAME_KICK_BY_PLAYER = 1,            // 被玩家T
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

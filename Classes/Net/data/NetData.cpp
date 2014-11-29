//
//  Data.cpp
//  Mahjong
//
//  Created by tiki on 14/10/29.
//
//

#include "NetData.h"
bool NetData::isHeartSafe  = true;
int NetData::HeartCount = 450;
int NetData::HeartTimeSafe = 30 * 1000;
bool NetData::isLock = false;
int NetData::recordCommonID = 0;
bool NetData::isOutLine = false;
int NetData::commonIDArray[] = {
    CHANNEL_ID_HEART,
    CHANNEL_ID_LOGIN_SERVER,
    CHANNEL_ID_ROOM_LIST,
    CHANNEL_ID_ENTER_ROOM,
    CHANNEL_ID_EXIT_ROOM,
    CHANNEL_ID_CLICK_READY,
    CHANNEL_ID_DOUBLE,
    CHANNEL_ID_TABLE_RANDOM_NUM,
    CHANNEL_ID_PUT_CARD
};

bool NetData::isHaveCommonID(int commonID){
    
    for(int i=0;i<sizeof(commonIDArray);i++){
        if(commonID == commonIDArray[i]){
            return true;
        }
    }
    return false;
}
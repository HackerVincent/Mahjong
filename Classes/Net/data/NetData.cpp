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
    C_ENTER_GAME,
    S_NOREQUEST_RESP
};

bool NetData::isHaveCommonID(int commonID){
    for(int i=0;i<sizeof(commonIDArray);i++){
        if(commonID == (commonIDArray[i]|0x01000000)){
            return true;
        }
    }
    return false;
}
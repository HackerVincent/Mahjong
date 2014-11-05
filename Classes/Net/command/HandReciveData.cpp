//
//  HandReciveData.cpp
//  Mahjong
//
//  Created by tiki on 14/10/29.
//
//

#include "HandReciveData.h"
#include "Net/data/NetData.h"
#include "ModelEnter.h"
bool HandReciveData::isUseReciveThis = false;
HandReciveData::HandReciveData(){
}
HandReciveData::~HandReciveData(){
}
static HandReciveData* instc = NULL;
HandReciveData* HandReciveData::getInstance(){
    if(instc == NULL){
        instc = new HandReciveData();
    }
    return instc;
}
void HandReciveData::put(HMessage* hms){
    reciveData.push_back(hms);
}

int HandReciveData::getPondSize(){
    return reciveData.size();
}

void HandReciveData::use(){
    if(reciveData.size()<=0){
        return;
    }
    
    for(auto e : reciveData)
    {
        auto mess = dynamic_cast<HMessage*>(e);
        /********* 消息头部 *********/
        short prefix = mess->getShort();        // 数据开始标志 固定为 -3000
        CCLOG("prefix-------->%hd",prefix);
        int occupy = mess->getInt();            // 占位  = 0
        CCLOG("occupy-------->%d",occupy);
        int uid = mess->getInt();               // 玩家id
        CCLOG("uid----------->%d",uid);
        int channelId = mess->getInt();         // 请求标志 (和request中一样)
        CCLOG("channelId----->%d",channelId);
        std::string skey = mess->getUTF8();     // 验证用 传空字符串
        CCLOG("skey---------->%s",skey.c_str());
        int totalLen = mess->getInt();          // 消息总长
        CCLOG("totalLen------>%d",totalLen);
        int dataLen = mess->getInt();           // 数据区长度
        CCLOG("dataLen------->%d",dataLen);
        /************ 数据区 ***********/
        char* recv = new char[dataLen];
        mess->getBytes((uint8_t*)recv, dataLen);
        auto messData = new HMessage((uint8_t*)recv,dataLen);
        /************  消息尾部  ************/
        short surffix = mess->getShort();          // 数据结尾标志 传  固定为 -4000
        CCLOG("surrix----->%hd",surffix);
        // 解析数据
        analysixData(messData);
        auto iter = std::find(reciveData.begin(), reciveData.end(), e);
        reciveData.erase(iter);
    }
    
    
//    vector<HMessage*>::iterator iter=reciveData.begin();
//    HMessage* mes = * iter;
//    mes->get();
//    mes->getInt();
//    int userid = mes->getLong();
//    char result = mes->get();//0成功
//    int commandID = mes->getInt();
//    if(NetData::isHaveCommonID(commandID))
//    {
//        
//    }
    
//    if(NetData::isHaveCommonID(commandID)){
//        if(commandID == (NetData::recordCommonID|0x01000000)){
//            NetData::isLock = false;
//            ModelEnter* currentCommand = new ModelEnter();
//            currentCommand->DealResponseCommand(mes);
//            if(NetData::recordCommonID != NetData::C_HEART_REQUEST){
//                GameData::Netresult = result;
//            }
//            NetData::recordCommonID = 0;
//        }else{
//            ModelEnter* currentCommand = new ModelEnter();
//            currentCommand->DealResponseCommand(mes);
//        }
//    }
//    reciveData.erase(iter);
}

void HandReciveData::analysixData(HMessage* mes)
{
    short prefix = mes->getShort();                 // 数据开始标志 固定为 -5000
    CCLOG("prefix------>%hd",prefix);
    int modleId = mes->getInt();                    // 模块ID
    CCLOG("modleId----->%d",modleId);
    if(NetData::isHaveCommonID(modleId))
    {
//        ModelEnter* currentCommand = new ModelEnter();
//        char* data = new char[mes->getlengths() - 10];
//        mes->getBytes((uint8_t*)data, mes->getlengths() - 10);
//        auto mesData = new HMessage((uint8_t*)data, mes->getlengths() - 10);
//        currentCommand->DealResponseCommand(mesData);
    }
    int a = mes->getInt();
    CCLOG("a----------->%d",a);
    short b = mes->getShort();
    CCLOG("b----------->%d",b);
    long c = mes->getLong();
    CCLOG("c----------->%ld",c);
    string d = mes->getUTF8();
    CCLOG("d----------->%s",d.c_str());
    short surffix = mes->getShort();
    CCLOG("c----------->%hd",surffix);
}
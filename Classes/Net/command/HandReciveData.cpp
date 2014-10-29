//
//  HandReciveData.cpp
//  Mahjong
//
//  Created by tiki on 14/10/29.
//
//

#include "HandReciveData.h"
#include "Net/data/NetData.h"
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
    vector<HMessage*>::iterator iter=reciveData.begin();
    HMessage* mes = * iter;
    mes->get();
    mes->getInt();
    int userid = mes->getLong();
    char result = mes->get();//0成功
    int commandID = mes->getInt();
    if(NetData::isHaveCommonID(commandID))
    {
        
    }
    
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
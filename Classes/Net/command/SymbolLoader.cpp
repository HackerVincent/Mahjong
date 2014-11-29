//
//  SymbolLoader.cpp
//  Mahjong
//
//  Created by tiki on 14/10/29.
//
//

#include "SymbolLoader.h"
#include "Net/data/NetData.h"
#include "Tools/HashMap.h"
#include "Net/reponse/ResponseRoomList.h"
#include "Net/reponse/ResponseTable.h"
#include "Net/reponse/ResponseExitRoom.h"
SymbolLoader* SymbolLoader::instanc = NULL;
SymbolLoader* SymbolLoader::getInstance(){
    if(instanc == NULL){
        instanc = new SymbolLoader();
    }
    return instanc;
}

SymbolLoader::SymbolLoader(){
    symbols = new Hashmap();
    symbols->put(NetData::MODLE_ID_ROOM_LIST,new ResponseRoomList());
    symbols->put(NetData::MODLE_ID_ENTER_ROOM,new ResponseTable());
    symbols->put(NetData::MODLE_ID_EXIT_ROOM, new ResponseExitRoom());
    
}

bool SymbolLoader::isHaveObject(int key){
    return symbols->isHaveObject(key);
}
ResponseCommand* SymbolLoader::get(int key){
    return symbols->get(key);
}
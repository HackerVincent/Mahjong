//
//  SymbolLoader.cpp
//  Mahjong
//
//  Created by tiki on 14/10/29.
//
//

#include "SymbolLoader.h"
#include "../data/NetData.h"
#include "HashMap.h"
SymbolLoader* SymbolLoader::instanc = NULL;
SymbolLoader* SymbolLoader::getInstance(){
    if(instanc == NULL){
        instanc = new SymbolLoader();
    }
    return instanc;
}
SymbolLoader::SymbolLoader(){
    symbols = new Hashmap();
//    symbols->put(NetData::MODEL_ID_ENTERGAME,new ResponseEnterGame());
//    symbols->put(NetData::MODEL_ID_USERINFO,new ResponseUserInfo());
    
}

bool SymbolLoader::isHaveObject(int key){
    return symbols->isHaveObject(key);
}
ResponseCommand* SymbolLoader::get(int key){
    return symbols->get(key);
}
//
//  HasMap.cpp
//  Mahjong
//
//  Created by tiki on 14/10/29.
//
//

#include "HashMap.h"
Hashmap::Hashmap(){
}
void Hashmap::put(int key,ResponseCommand* value)
{
    bool isHaveKey = false;
    for(int i = 0;i<array.size();i++){
        if(array[i]!=NULL && array[i]->getKey() == key){
            array[i]->setValue(value);
            isHaveKey = true;
        }
    }
    if(!isHaveKey){
        HashEntry* temp = new HashEntry(value,key);
        array.push_back(temp);
    }
}
void Hashmap::remove(int key){
    for(int i = 0;i<array.size();i++){
        if(array[i]!=NULL && array[i]->getKey() == key){
            array[i] = NULL;
        }
    }
}
void Hashmap::removeAllObject(){
    for(int i = 0;i<array.size();i++){
        array[i] = NULL;
    }
    array.clear();
}
int Hashmap::size(){
    int lenghs = 0;
    for(int i = 0;i<array.size();i++){
        if(array[i]!=NULL){
            lenghs++;
        }
    }
    return lenghs;
}

bool Hashmap::isHaveObject(int key){
    bool isHaveKey = false;
    for(int i = 0;i<array.size();i++){
        if(array[i]!=NULL && array[i]->getKey() == key){
            isHaveKey = true;
        }
    }
    return isHaveKey;
}

ResponseCommand* Hashmap::get(int key){
    for(int i = 0;i<array.size();i++){
        if(array[i]!=NULL && array[i]->getKey() == key){
            return array[i]->getValue();
        }
    }
    return NULL;
}
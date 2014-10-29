//
//  HashEntry.cpp
//  Mahjong
//
//  Created by tiki on 14/10/29.
//
//

#include "HashEntry.h"
HashEntry::HashEntry(ResponseCommand* si,int kd){
    this->index = kd;
    this->rs = si;
}
ResponseCommand* HashEntry::getValue(){
    return rs;	;
}
void HashEntry::setValue(ResponseCommand* si){
    this->rs = si;
}
int HashEntry::getKey(){
    return this->index;
}
void HashEntry::setKey(int kd){
    this->index = kd;
}
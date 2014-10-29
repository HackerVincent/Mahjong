//
//  HasMap.h
//  Mahjong
//
//  Created by tiki on 14/10/29.
//
//

#ifndef __Mahjong__HasMap__
#define __Mahjong__HasMap__

#include <stdio.h>
#include "ResponseCommand.h"
#include "cocos2d.h"
#include "HashEntry.h"
#include "HashEntry.h"
using namespace std;
class Hashmap{
private:
    vector<HashEntry*> array;
public:
    Hashmap();
    void put(int key,ResponseCommand* value);
    void remove(int key);
    int size();
    void removeAllObject();
    ResponseCommand* get(int key);
    bool isHaveObject(int key);
};
#endif /* defined(__Mahjong__HasMap__) */

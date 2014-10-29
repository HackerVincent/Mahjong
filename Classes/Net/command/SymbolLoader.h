//
//  SymbolLoader.h
//  Mahjong
//
//  Created by tiki on 14/10/29.
//
//

#ifndef __Mahjong__SymbolLoader__
#define __Mahjong__SymbolLoader__

#include <stdio.h>
#include "cocos2d.h"
#include "HashMap.h"
#include "ResponseCommand.h"
class SymbolLoader{
public:
    Hashmap* symbols;
    bool isHaveObject(int key);
    static SymbolLoader* getInstance();
    static SymbolLoader* instanc;
    SymbolLoader();
    ResponseCommand* get(int key);
};
#endif /* defined(__Mahjong__SymbolLoader__) */

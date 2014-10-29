//
//  HashEntry.h
//  Mahjong
//
//  Created by tiki on 14/10/29.
//
//

#ifndef __Mahjong__HashEntry__
#define __Mahjong__HashEntry__

#include <stdio.h>
#include "ResponseCommand.h"
class HashEntry{
private:
    ResponseCommand* rs;
    int index;
public:
    HashEntry(ResponseCommand* si,int kd);
    ResponseCommand* getValue();
    void setValue(ResponseCommand* si);
    int getKey();
    void setKey(int kd);
};

#endif /* defined(__Mahjong__HashEntry__) */

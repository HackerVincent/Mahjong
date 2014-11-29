//
//  DynamicData.cpp
//  Mahjong
//
//  Created by tiki on 14/11/26.
//
//

#include "DynamicData.h"

DynamicData* DynamicData::s_dynamic = nullptr;

DynamicData* DynamicData::getInstance()
{
    if (!s_dynamic)
    {
        s_dynamic = new DynamicData();
    }
    return s_dynamic;
}
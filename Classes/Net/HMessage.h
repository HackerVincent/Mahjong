//
//  HMessage.h
//
//  Created by Tiki
//  Copyright (c) 2012年 AS. All rights reserved.
//

#ifndef CocosTest_HMessage_h
#define CocosTest_HMessage_h
 
#include "cocos2d.h"
#if(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
#include<cstdint>
#endif
#include <iostream>


class HMessage {
private:
    int count;
    int size;
    int corlengths;
    uint8_t* buf;
    bool m_releaseBuffer;
    
    void init(int size){
        count = 0;
        this->size = size;
        buf = new uint8_t[size];
        m_releaseBuffer = true;
    }
    
    void ensureCapacity(int minCapacity){
        if (minCapacity - size > 0){
            int oldCapacity = size;
            int newCapacity = oldCapacity << 1;
            if (newCapacity - minCapacity < 0)
                newCapacity = minCapacity;
            if (newCapacity < 0) {
                if (minCapacity < 0) // overflow
                    return;
                newCapacity = 2147483647;
            }
            uint8_t* newBuf = new uint8_t[newCapacity];
            memset(newBuf, 0, newCapacity);
            memcpy(newBuf, buf, oldCapacity);
            delete[] buf;
            buf = newBuf;
            size = newCapacity;
        }
    }
    
    bool checkSize(int readSize){
        if(count + readSize > size){
            return false;
        }
        return true;
    }
    
    
public:
    HMessage(){
        corlengths = 0;
        init(512);
    }
    
    HMessage(int size){
        corlengths = size;
        init(size);
    }
    
    HMessage(uint8_t* buf, int size){
        //用buff初始化，供读取用
        initWithBuffer(buf, size);
        corlengths = size;
    }
    int getlengths();
    void initWithBuffer(uint8_t* buf, int size){
        //用buff初始化，供读取用
        this->size = size;
        this->buf = buf;
        count = 0;
    }
    
    void setPosition(int position){
        count = position;
    }
    
    int position(){
        return count;
    }
    
    void reset(){
        count = 0;
    }
    
    void setReleaseBuffer(bool m_releaseBuffer){
        this->m_releaseBuffer = m_releaseBuffer;
    }
    
    void put(uint8_t byte);
    void putShort(uint16_t v);
    void putInt(uint32_t v);
    void putLong(uint64_t v);
    void putWString(const wchar_t* str);
    void putBytes(const uint8_t* byte, int len);
    void putUTF8(const char* str);
    void putUTF16BE(const char* str);
    
    uint8_t get();
    uint16_t getShort();
    uint32_t getInt();
    uint64_t getLong();
    void getBytes(uint8_t* pBuffer, int len);
    wchar_t* getWString();
    char* getUTF8();
    char* getUTF8(short strByteLen);
    char* getUTF16BE();
    
    uint8_t* getBuf();
    
    void setNumber(int num, int off, int len);
    
    void skip(int bytes);
    
    ~HMessage(){
        if(m_releaseBuffer)
            delete[] buf;
    }
    
};

#endif

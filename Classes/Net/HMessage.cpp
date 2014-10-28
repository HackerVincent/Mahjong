//
//  HMessage.cpp
//
//  Created by Tiki 
//  Copyright (c) 2012年 AS. All rights reserved.
//

#include <iostream>
#include "HMessage.h"

void HMessage::put(uint8_t byte){
    ensureCapacity(position() + 1);
    buf[count++] = byte;
    corlengths += 1;
}

uint8_t HMessage::get(){
    if(!checkSize(1)){
        return 0;
    }
    corlengths -= 1;
    uint8_t ret = buf[count++];
    return ret;
}
int HMessage::getlengths(){
    return corlengths;
}
void HMessage::putShort(uint16_t v){
    ensureCapacity(position() + 2);
    buf[count++] = (v >> 8) & 0xff;
    buf[count++] = v & 0xff;
    corlengths += 2;
}

uint16_t HMessage::getShort(){
    if(!checkSize(2)){
        return 0;
    }
    corlengths -= 2;
    uint16_t r1 = buf[count++] << 8;
    uint16_t r2 = buf[count++];
    uint16_t ret = r1 | r2;
    return ret;
}

void HMessage::putInt(uint32_t v){
    ensureCapacity(position() + 4);
    buf[count++] = (v >> 24) & 0xff;
    buf[count++] = (v >> 16) & 0xff;
    buf[count++] = (v >> 8) & 0xff;
    buf[count++] = v & 0xff;
    corlengths += 4;
}

uint32_t HMessage::getInt(){
    if(!checkSize(4)){
        return 0;
    }
    corlengths -= 4;
    uint32_t ret = buf[count++] << 24;
    ret|= buf[count++] << 16;
    ret|= buf[count++] <<8;
    ret|=buf[count++];
    return ret;
}

void HMessage::putLong(uint64_t v){
    ensureCapacity(position() + 8);
    buf[count++] = (v >> 56) & 0xff;
    buf[count++] = (v >> 48) & 0xff;
    buf[count++] = (v >> 40) & 0xff;
    buf[count++] = (v >> 32) & 0xff;
    buf[count++] = (v >> 24) & 0xff;
    buf[count++] = (v >> 16) & 0xff;
    buf[count++] = (v >> 8) & 0xff;
    buf[count++] = v & 0xff;
    corlengths += 8;
}

uint64_t HMessage::getLong(){
    if(!checkSize(8)){
        return 0;
    }
    corlengths -= 8;
    uint64_t ret = 0;
    ret = (uint64_t)buf[count++] << 56;
    ret|= (uint64_t)buf[count++] << 48;
    ret|= (uint64_t)buf[count++] << 40;
    ret|= (uint64_t)buf[count++] << 32;
    ret|= buf[count++] << 24;
    ret|= buf[count++] << 16;
    ret|= buf[count++] <<8;
    ret|=buf[count++];
    return ret;
    
}

void HMessage::putBytes(const uint8_t *byte, int len){
    ensureCapacity(position() + len);
    memcpy(&buf[position()], byte, len);
    count += len;
    corlengths += len;
}

void HMessage::getBytes(uint8_t* pBuffer, int len){
    if(!checkSize(len)){
        return;
    }
    corlengths -= len;
    memcpy(pBuffer, &buf[count], len);
    count+=len;
}

void HMessage::putUTF8(const char *str){
    int len = 0;
    int idx = 0;
    while(str[idx]!='\0'){
        len++;
        idx++;
    }
    if(!checkSize(len)){
        return;
    }
    putShort(len);
    putBytes((unsigned char*)str, len);
}

void HMessage::putWString(const wchar_t *str){
    int len = wcslen(str);
    HMessage utfData;
    short utfLen = 0;
    
    for (int i=0; i<len; i++) {
        wchar_t wc = str[i];
        char cs[2] = {static_cast<char>(wc & 0xff), static_cast<char>(wc >> 8)};
        
        if(wc<=0x7f){         // ASCII  0x00 ~ 0x7f
            utfData.put(cs[0]);
            utfLen++;
        }else if(wc<=0x7ff){  // 0x080 ~ 0x7ff
            utfData.put(0xC0 | ((wc >>  6) & 0x1F));
            utfData.put(0x80 | ((wc >>  0) & 0x3F));
            utfLen+=2;
        }else{                      // 0x0800 ~ 0xFFFF
            utfData.put(0xE0 | ((wc >> 12) & 0x0F));
            utfData.put(0x80 | ((wc >>  6) & 0x3F));
            utfData.put(0x80 | ((wc >>  0) & 0x3F));
            utfLen+=3;
        }
    }
    
    putShort(utfLen);
    const uint8_t* utf = utfData.getBuf();
    putBytes(utf, utfData.position());
    delete[] utf;
}

char* HMessage::getUTF8(short strByteLen){
    short utfLen = strByteLen;//getShort();
    if(!checkSize(utfLen)){
//        return '\0';
        return nullptr;
    }
    char* utfBuffer = new char[utfLen + 1];
    getBytes((unsigned char*)utfBuffer, utfLen);
    utfBuffer[utfLen] = '\0';
    
    strByteLen = utfLen + 2;
    
    return utfBuffer;
}

char* HMessage::getUTF8(){
    int len = getShort();
    return getUTF8(len);
}

wchar_t* HMessage::getWString(){
    short utfLen = getShort();
    wchar_t* charBuff = new wchar_t[utfLen];
    
    wchar_t c,c2,c3;
    int utfCount = 0;
    int charCount = 0;
    while (utfCount < utfLen) {
        c = get();
        switch (c >> 4) {
            case 0:case 1:case 2:case 3:case 4:case 5:case 6:case 7:
                utfCount++;
                charBuff[charCount++] = c;
                break;
            case 12: case 13:
                utfCount+=2;
                c2 = get();
                charBuff[charCount++] = (((c & 0x1F) << 6) | (c2 & 0x3F));
                
                break;
            case 14:
                utfCount+=3;
                c2 = get();
                c3 = get();
                charBuff[charCount++] = (((c & 0x0F) << 12) | ((c2 & 0x3F) << 6)  | ((c3 & 0x3F) << 0));
        }
    }
    
    wchar_t* ret = new wchar_t[charCount + 1];
    memcpy(ret, charBuff, charCount * sizeof(*ret));
    ret[charCount] = '\0';
    delete[] charBuff;
    return ret;
}

uint8_t* HMessage::getBuf(){
    uint8_t* ret = new uint8_t[count];
    memcpy(ret, buf, count);
    return ret;
}


void HMessage::setNumber(int num, int off, int len) {
    for (int i = len - 1; i >= 0; i--) {
        buf[off + i] = (char) (num & 0xff);
        num >>= 8;
    }
}

char* HMessage::getUTF16BE(){
    int slen = get();
    if((slen & 0x80)!=0){
        int slen2 = get();
        slen = ((slen & 0x7f) << 8) + slen2;
    }
    
    int strLen = slen * 2;
    
    char* pRet = new char[strLen + 1];
    memcpy(pRet, &buf[count], strLen);
    count+=strLen;
    
    pRet[strLen] = '\0';
    
    return pRet;
}

void HMessage::skip(int bytes){
    if(checkSize(bytes)){
        count += bytes;
    }
}
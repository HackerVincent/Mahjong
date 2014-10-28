//
//  MThread.h
//  Mahjong
//
//  Created by tiki on 14/10/27.
//
//

#ifndef __Mahjong__MThread__
#define __Mahjong__MThread__

#include <stdio.h>
#include "cocos2d.h"
#include "pthread.h"
#define MTHREAD() MThread::getInstance()
using namespace cocos2d;

class MThread
{
protected:
    pthread_t mThread_send;
    pthread_t mThread_recv;
public:
    MThread();
    void* ThreadFunction_Send(void* arg);
    void* ThreadFunction_Recv(void* arg);
    bool createThreadSend();
    bool createThreadRecv();
    static MThread* getInstance();
    void stopNet();
    bool threadProcess(void* data);
};


#endif /* defined(__Mahjong__MThread__) */

//
//  MThread.cpp
//  Mahjong
//
//  Created by tiki on 14/10/27.
//
//

#include "MThread.h"
MThread::MThread()
{
    
}
void MThread::stopNet(){
//    SendNetWork::getInstance()->stopNetWork();
//    ReciveNetWork::getInstance()->stopNetWork();
}
static bool isStopNetRecv = false;
static bool isStopNetSend = false;
void* MThread::ThreadFunction_Send(void *arg)
{
//    isStopNetSend = true;
//    SendNetWork::getInstance()->DealNetWorkThread();
//    isStopNetSend = false;
//    if(!isStopNetSend && !isStopNetRecv){
//        CommonCommand::getInstance()->stop();
//    }
//    pthread_exit(NULL);
    return NULL;
}

void* MThread::ThreadFunction_Recv(void *arg)
{
//    isStopNetRecv = true;
//    ReciveNetWork::getInstance()->SocketThread();
//    isStopNetRecv = false;
//    if(!isStopNetSend && !isStopNetRecv){
//        CommonCommand::getInstance()->stop();
//    }
//    pthread_exit(NULL);
    return NULL;
}
static MThread* smthread = NULL;

MThread* MThread::getInstance()
{
    if(!smthread){
        smthread = new MThread();
    }
    return smthread;
}

static void* ThreadProcess(void* data)
{
    MTHREAD()->ThreadFunction_Send(data);
    return NULL;
}

static void* ThreadProcess_Recv(void* data)
{
    MTHREAD()->ThreadFunction_Recv(data);
    return NULL;
}


bool MThread::createThreadSend()
{
    int errCode = 0;
    do{
        pthread_attr_t tAttr;
        errCode = pthread_attr_init(&tAttr);
        CC_BREAK_IF(errCode != 0);
        errCode = pthread_attr_setdetachstate(&tAttr,PTHREAD_CREATE_DETACHED);
        if(errCode != 0){
            pthread_attr_destroy(&tAttr);
            break;
        }
        errCode = pthread_create(&mThread_send,NULL,ThreadProcess,this);
    }while(0);
    return errCode;
}

bool MThread::createThreadRecv()
{
    int errCode = 0;
    do{
        pthread_attr_t tAttr;
        errCode = pthread_attr_init(&tAttr);
        CC_BREAK_IF(errCode != 0);
        errCode = pthread_attr_setdetachstate(&tAttr,PTHREAD_CREATE_DETACHED);
        if(errCode != 0){
            pthread_attr_destroy(&tAttr);
            break;
        }
        errCode = pthread_create(&mThread_recv,NULL,ThreadProcess_Recv,this);
    }while(0);
    return errCode;
}
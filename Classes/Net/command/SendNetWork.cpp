//
//  SendNetWork.cpp
//  Mahjong
//
//  Created by tiki on 14/10/31.
//
//

#include "SendNetWork.h"
#include "Net/data/NetData.h"
#include "Tools/HMessage.h"
#include "CommonCommand.h"
//#include "RequestEnterGame.h"
//#include "MThread.h"

using namespace std;

SendNetWork::SendNetWork()
:isRuning(false)
,isRunHeader(false)
,reTryCount(0)
{
    m_RequestCommandList.clear();
}

SendNetWork::~SendNetWork()
{
    m_RequestCommandList.clear();
}

SendNetWork* SendNetWork::instance = NULL;
SendNetWork* SendNetWork::getInstance(){
    if(instance == NULL){
        instance = new SendNetWork();
        instance->isRuning = true;
        instance->isRunHeader = true;
        NetData::isHeartSafe = true;
    }
    return instance;
}
void SendNetWork::stopNetWork(){
    if(instance != NULL){
        instance->isRuning = false;
        instance = NULL;
    }
}
void SendNetWork::DealNetWorkThread(){
//    while(isRuning){
//        if (!isRuning) {
//            return;
//        }
//        if(isRunHeader)
//            RoleModel::getInstance()->sendSysHeart();
        sendCommandDataToServer();
//#if(CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)//条件编译语句
//        usleep(100*1000);//微秒
//#elif(CC_TARGET_PLATFORM == CC_PLATFORM_WIN32)
//        Sleep(100);//毫秒
//#elif(CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
//        usleep(30*1000);//微秒
//#endif
//    }
}
void SendNetWork::AddNetCommand(RequestCommand* respCommand)
{
    if (respCommand != NULL)
    {
        m_RequestCommandList.push_back(respCommand);
        
    }
}
void SendNetWork::sendCommandDataToServer(){
    if (CommonCommand::getInstance()->isConnected())
    {
        if (m_RequestCommandList.size() > 0)
        {
            for(auto e : m_RequestCommandList)
            {
                auto request = dynamic_cast<RequestCommand*>(e);
//                RequestCommand* requestCommand = (RequestCommand*) m_RequestCommandList[0];
                HMessage* sendData = request->CreatCmdPacket();
                if (CommonCommand::getInstance()->sendMessage(sendData)) {// 网络能发送成功,移除发送指令
                    reTryCount = 0;
//                    vector<RequestCommand*>::iterator iter=m_RequestCommandList.begin();
//                    m_RequestCommandList.erase(iter);
                    
                    auto star_iter = std::find(m_RequestCommandList.begin(),m_RequestCommandList.end(),e);
                    m_RequestCommandList.erase(star_iter);
                } else {
                    reTryCount++;
                    if (reTryCount > 3)
                    {
                        // 					MThread::getInstance()->stopNet();
                        // 					MThread::getInstance()->createThreadSend();
                        // 					MThread::getInstance()->createThreadRecv();
                    }
                }
            }
            
            
        }
    }
}
#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "network/WebSocket.h"

class HelloWorld : public cocos2d::Layer, public cocos2d::network::WebSocket::Delegate
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();  
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    
    virtual void onOpen(cocos2d::network::WebSocket* ws);
    virtual void onMessage(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::Data& data);
    virtual void onClose(cocos2d::network::WebSocket* ws);
    virtual void onError(cocos2d::network::WebSocket* ws, const cocos2d::network::WebSocket::ErrorCode& error);
    
    
    // implement the "static create()" method manually
    CREATE_FUNC(HelloWorld);
    
private:
    cocos2d::network::WebSocket* _wsiSendText;
    cocos2d::network::WebSocket* _wsiSendBingary;
    cocos2d::network::WebSocket* _wsiError;
};

#endif // __HELLOWORLD_SCENE_H__

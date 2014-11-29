//
//  GameData.h
//  HeroRunRunRunNew
//
//  Created by tiki on 14-10-14.
//
//

#ifndef __HeroRunRunRunNew__GameData__
#define __HeroRunRunRunNew__GameData__

#include <stdio.h>
#include "cocos2d.h"
class GameData
{
public:
    GameData();
    virtual ~GameData();
    static GameData* getInstance();
    void save();
    void load();
    
    
    // 登陆数据
    void setID(int id){ _id = id;};
    int getID(){return _id;};
    
    void setUserId(std::string userId){ _userId = userId;};
    std::string getUserId(){return _userId;};
    
    void setUserPass(std::string userPass){ _userPass = userPass;};
    std::string getUserPass(){return _userPass;};
    
    void setUserName(std::string userName){ _userName = userName;};
    std::string getUserName(){return _userName;};
    
    void setIconType(int iconType){ _iconType = iconType;};
    int getIconType(){return _iconType;};
    
    void setSex(int sex){ _sex = sex;};
    int getSet(){return _sex;};
    
    void setSkey(std::string skey){ _skey = skey;};
    std::string getSkey(){return _skey;};
    
    void setIP(std::string Ip){ _ip = Ip;};
    std::string getIP(){return _ip;};
    
    void setPort(std::string Port){ _port = Port;};
    std::string getPort(){return _port;};
    
    void setState(int State){ _state = State;};
    int getState(){return _state;};
    
    void setUpdate(bool update){ _update = update;};
    bool getUpdate(){return _update;};
    
    void setDownUrl(std::string downUrl){ _downUrl = downUrl;};
    std::string getDownUrl(){return _downUrl;};
    
protected:
    // 玩家uid，用于登陆游戏服务器
    int _id;
    // 服务器自动分配的数字账号
    std::string _userId;
    // 账号密码
    std::string _userPass;
    // 玩家账号名，游客为userId，第三方用户则为第三方账号
    std::string _userName;
    // 0系统(默认)  1 自定义 icon ：系统id序号或自定义头像url
    int _iconType;
    // 0未知(默认) 1男 2 女
    int _sex;
    // 验证字符串，登陆游戏用
    std::string _skey;
    // ip
    std::string _ip;
    // port
    std::string _port;
    // 服务器状态（-1维护 0正常） ，若不为0，提示服务器正在维护
    int _state;
    // 用于版本更新，如果update为true，则直接下载
    bool _update;
    // 强制更新
    std::string _downUrl;
    
};
#endif /* defined(__Mahjong__GameData__) */

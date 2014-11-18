#ifndef _JIONSX_H_
#define _JIONSX_H_
#include "cocos2d.h"
#include <string>
using namespace std;
class jionsx{
public:
	jionsx(string temp);
	string tempString;
	int getIntValue(string key);
	string getStringValue(string key);
};
#endif
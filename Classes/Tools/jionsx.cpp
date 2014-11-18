#include "jionsx.h"
jionsx::jionsx(string temp){
	tempString = temp;
}
int jionsx::getIntValue(string key){
	int start = tempString.find("\""+key+"\":");
	start = tempString.find(":",start);
	int end = tempString.find(",",start);
	int end1 = tempString.find("},",start);
	string skf = "";
	if(end > end1){
		skf = tempString.substr(start+strlen(":"),end1-start-strlen(":"));
	}else{
		skf = tempString.substr(start+strlen(":"),end-start-strlen(":"));
	}
	return std::atoi(skf.c_str());
}
string jionsx::getStringValue(string key){
	int start = tempString.find("\""+key+"\":");
	start = tempString.find(":\"",start);
	int end = tempString.find("\",",start);
	int end1 = tempString.find("\"},",start);
	string skf = "";
	if(end == -1 && end1 == -1){
		end1 = tempString.find_last_of("\"");
		skf = tempString.substr(start+strlen(":\""),end1-start-strlen(":\""));
	}else{
		if(end1 == -1){
			skf = tempString.substr(start+strlen(":\""),end-start-strlen(":\""));
		}else{
			if(end == -1){
				skf = tempString.substr(start+strlen(":\""),end1-start-strlen(":\""));
			}else{
				if(end > end1){
					skf = tempString.substr(start+strlen(":\""),end1-start-strlen(":\""));
				}else{
					skf = tempString.substr(start+strlen(":\""),end-start-strlen(":\""));
				}
			}
		}
	}
	
	return skf;
}
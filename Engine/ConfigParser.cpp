/*
 * ConfigParser.cpp
 *
 *  Created on: Aug 25, 2014
 *      Author: Dean
 */

#include "ConfigParser.h"

namespace enDJIN{
	ConfigParser::ConfigParser(const Json::Value *newConfig){
		config=((Json::Value *)newConfig);
	}

	const Json::Value *ConfigParser::getConfig() const {
		return config;
	}

	ConfigParser::~ConfigParser() {
		// TODO Auto-generated destructor stub
	}

	KeyMappings* ConfigParser::generateKeyMap(){
		KeyMappings *keyMap = new KeyMappings();
		return keyMap;
	}

	Json::Value ConfigParser::getItem(std::string itemName, int index){
		return (*config)[itemName][index];
	}
//gamescreens
};

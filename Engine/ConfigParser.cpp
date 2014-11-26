/*
 * ConfigParser.cpp
 *
 *  Created on: Aug 25, 2014
 *      Author: Dean
 */

#include "ConfigParser.h"

namespace enDJIN{
	ConfigParser::ConfigParser(const std::string &jsonDocument) {
		Json::Reader *jsonReader=new Json::Reader();
		bool greatSuccess=jsonReader->parse(jsonDocument,config, true);
		if(!greatSuccess){
			std::exit(-1);
		}


	}

	const Json::Value *ConfigParser::getConfig() const {
		return &config;
	}

	ConfigParser::~ConfigParser() {
		// TODO Auto-generated destructor stub
	}
	KeyMappings* ConfigParser::generateKeyMap(){
		KeyMappings *keyMap = new KeyMappings();
		return keyMap;
	}

};

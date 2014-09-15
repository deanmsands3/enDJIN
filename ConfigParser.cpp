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
		Json::Value jsonRoot;
		bool greatSuccess=jsonReader->parse(jsonDocument,jsonRoot, true);
		if(!greatSuccess){
			std::exit(-1);
		}
		const Json::Value config = jsonRoot["config"];

	}

	ConfigParser::~ConfigParser() {
		// TODO Auto-generated destructor stub
	}
};

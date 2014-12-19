/*
 * DataParser.cpp
 *
 *  Created on: Dec 19, 2014
 *      Author: Dean
 */

#include "DataParser.h"

namespace enDJIN {


DataParser::DataParser(const std::string &jsonDocument) {
	Json::Reader *jsonReader=new Json::Reader();
	jvIndex=parse(jsonReader, "index.json");
	jvConfig=parse(jsonReader, (*jvIndex)["config"].asString());
	jvGameScreens=parse(jsonReader, (*jvIndex)["gamescreens"].asString());
	jvActors=parse(jsonReader, (*jvIndex)["actors"].asString());
	delete jsonReader;
}
Json::Value *DataParser::parse(Json::Reader *jsonReader, std::string fileName){
	Json::Value *target=new Json::Value();
	bool greatSuccess=jsonReader->parse(fileName,*target, true);
	if(!greatSuccess){
		delete target;
		std::exit(-1);
	}
	return target;
}

Json::Value *DataParser::getConfig(){
	return jvConfig;
}
Json::Value *DataParser::getGameScreens(){
	return jvGameScreens;
}

Json::Value *DataParser::getActors(){
	return jvActors;
}

DataParser::~DataParser() {
	delete jvIndex;
	delete jvConfig;
	delete jvGameScreens;
	delete jvActors;
}

} /* namespace enDJIN */

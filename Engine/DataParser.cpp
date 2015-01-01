/*
 * DataParser.cpp
 *
 *  Created on: Dec 19, 2014
 *      Author: Dean
 */

#include "DataParser.h"

namespace enDJIN {


DataParser::DataParser(const std::string &jsonDocument) {
	std::string indexJSON=_dataFolder+"/index.json";
	std::string configJSON;
	std::string gameScreensJSON;
	std::string actorsJSON;
	Json::Reader *jsonReader=new Json::Reader();
	_jvIndex=_parse(jsonReader, indexJSON);
	configJSON=
			_dataFolder+"/"+(*_jvIndex)["config"]["Folder"].asString()
			+"/"+(*_jvIndex)["config"]["File"].asString();
	_jvConfig=_parse(jsonReader, (*_jvIndex)["config"].asString());
	_jvGameScreens=_parse(jsonReader, (*_jvIndex)["gamescreens"].asString());
	_jvActors=_parse(jsonReader, (*_jvIndex)["actors"].asString());
	delete jsonReader;
}
Json::Value *DataParser::_parse(Json::Reader *jsonReader, std::string fileName){
	Json::Value *target=new Json::Value();
	bool greatSuccess=jsonReader->parse(fileName,*target, true);
	if(!greatSuccess){
		delete target;
		std::cerr<<"Error loading "<<fileName<<std::endl;
		std::exit(-1);
	}
	return target;
}

Json::Value *DataParser::getConfig(){
	return _jvConfig;
}
Json::Value *DataParser::getGameScreens(){
	return _jvGameScreens;
}

Json::Value *DataParser::getActors(){
	return _jvActors;
}

const std::string& DataParser::getDataFolder() {
	return DataParser::_dataFolder;
}

void DataParser::setDataFolder(const std::string& dataFolder) {
	DataParser::_dataFolder = dataFolder;
}
std::string DataParser::_dataFolder;

DataParser::~DataParser() {
	delete _jvActors;
	delete _jvGameScreens;
	delete _jvConfig;
	delete _jvIndex;
}

} /* namespace enDJIN */

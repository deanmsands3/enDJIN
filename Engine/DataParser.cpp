/*
 * DataParser.cpp
 *
 *  Created on: Dec 19, 2014
 *      Author: Dean
 */

#include "DataParser.h"

namespace enDJIN {

DataParser::DataParser(const std::string &jsonDocument) {
	std::string indexJSON=(_dataFolder / "index.json").string();
	std::string configJSON;
	std::string gameScreensJSON;
	std::string actorsJSON;
	Json::Reader *jsonReader=new Json::Reader();
	_jvIndex=_parse(jsonReader, indexJSON);
	std::string configFolder=(*_jvIndex)["config"]["Folder"].asString();
	std::string configFile=(*_jvIndex)["config"]["File"].asString();
	configJSON=(_dataFolder / configFolder / configFile).string();
	_jvConfig=_parse(jsonReader, configJSON);

	std::string gameScreensFolder=(*_jvIndex)["gamescreens"]["Folder"].asString();
	std::string gameScreensFile=(*_jvIndex)["gamescreens"]["File"].asString();
	gameScreensJSON=(_dataFolder / gameScreensFolder / gameScreensFile).string();

	_jvGameScreens=_parse(jsonReader, gameScreensJSON);
	_jvActors=_parse(jsonReader, (*_jvIndex)["actors"].asString());
	delete jsonReader;
}

Json::Value *_parseFile(Json::Reader *jsonReader, std::string pathName){
	Json::Value *target=new Json::Value();
	bool greatSuccess=jsonReader->parse(pathName,*target, true);
	if(!greatSuccess){
		delete target;
		std::cerr<<"Error loading "<<pathName<<std::endl;
		std::exit(-1);
	}
	return target;
}

Json::Value *_parse(Json::Reader *jsonReader, boost::filesystem::path pathName){
	return _parseFile(jsonReader, pathName.string());
}

Json::Value *DataParser::_parse(Json::Reader *jsonReader, std::string indexName){
	if(_jvIndex==NULL){return NULL;}
	std::string configFolder=(*_jvIndex)[indexName]["Folder"].asString();
	std::string configFile=(*_jvIndex)[indexName]["File"].asString();
	std::string configJSON=(_dataFolder / configFolder / configFile).string();
	return _parseFile(jsonReader, configJSON);
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
	return DataParser::_dataFolder.string();
}

void DataParser::setDataFolder(const std::string& dataFolder) {
	DataParser::_dataFolder = dataFolder;
}

void DataParser::setDataFolder(const boost::filesystem::path& folderPath) {
	DataParser::_dataFolder = folderPath;
}

DataParser::~DataParser() {
	delete _jvActors;
	delete _jvGameScreens;
	delete _jvConfig;
	delete _jvIndex;
}
//Statics
boost::filesystem::path DataParser::_dataFolder;

} /* namespace enDJIN */

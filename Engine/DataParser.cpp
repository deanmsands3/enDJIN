/*
 * DataParser.cpp
 *
 *  Created on: Dec 19, 2014
 *      Author: Dean
 */

#include "DataParser.h"

namespace enDJIN {

DataParser::DataParser(const std::string &jsonDocument) {
	//	std::cout<<boost::filesystem::current_path()<<std::endl;

	//std::string indexJSON=(DataParser::_dataFolder / "index.json").string();
	std::string indexJSON="index.json";
	std::string configJSON;
	std::string gameScreensJSON;
	std::string actorsJSON;
	Json::Reader *jsonReader=new Json::Reader();
	_jvIndex=_parseFile(jsonReader, indexJSON);
	_jvConfig=_parseIndex(jsonReader, "config");
	_jvGameScreens=_parseIndex(jsonReader, "gamescreens");
	_jvEntities=_parseIndex(jsonReader, "entities");
	_jvTiles=_parseIndex(jsonReader, "tiles");
	_jvWorlds=_parseIndex(jsonReader, "worlds");
	delete jsonReader;
}

Json::Value *DataParser::_parseFile(Json::Reader *jsonReader, std::string pathName){
	Json::Value *target=new Json::Value();
	bool greatSuccess=true;
	try{
		std::ifstream jsonFile(pathName);
		jsonFile>>(*target);
		jsonFile.close();
	}catch(std::exception &e){
		std::cout<<"There was an error:"<<std::endl;
		greatSuccess=false;
	}
	if(!greatSuccess){
		std::cerr<<"Error loading "<<pathName<<std::endl;
		std::exit(-1);
	}


	return target;
}

Json::Value *DataParser::_parsePath(Json::Reader *jsonReader, boost::filesystem::path pathName){
	return _parseFile(jsonReader, pathName.string());
}


Json::Value *DataParser::_parseIndex(Json::Reader *jsonReader, std::string indexName){
	std::cout<<"Parsing:"<<indexName<<std::endl;
	if(_jvIndex==NULL){return NULL;}
	std::string configFolder=(*_jvIndex)[indexName]["folder"].asString();
	std::string configFile=(*_jvIndex)[indexName]["file"].asString();
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
	return _jvEntities;
}

const std::string& DataParser::getDataFolder() {
	return DataParser::_dataFolder.string();
}

void DataParser::setDataFolder(const char* dataFolder) {
	boost::filesystem::current_path(dataFolder);
	DataParser::_dataFolder = boost::filesystem::current_path();
}

void DataParser::setDataFolder(const std::string& dataFolder) {
	boost::filesystem::current_path(dataFolder);
	DataParser::_dataFolder = boost::filesystem::current_path();
}

void DataParser::setDataFolder(const boost::filesystem::path& folderPath) {
	boost::filesystem::current_path(folderPath);
	DataParser::_dataFolder = boost::filesystem::current_path();
}

DataParser::~DataParser() {
	delete _jvEntities;
	delete _jvGameScreens;
	delete _jvConfig;
	delete _jvIndex;
}
//Statics
boost::filesystem::path DataParser::_dataFolder;

} /* namespace enDJIN */

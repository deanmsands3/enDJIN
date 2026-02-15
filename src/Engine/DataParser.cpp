/*
 * DataParser.cpp
 *
 *  Created on: Dec 19, 2014
 *      Author: Dean
 */

#include "DataParser.h"

namespace enDJIN {

DataParser::DataParser(const std::string &jsonDocument) {
	std::string valueName;
	//Parse JSON index and store in map
	try{
		_jvIndex=_parseFile(jsonDocument);	//Parse in the main Index File
		FILE_LOG(logINFO)<<"Index Parsed"<<std::endl;
		//Loop through index and parse the sub-indexes
		for(auto rootName:_jvIndex->getMemberNames()){
			FILE_LOG(logINFO)<<"Parsing "<<rootName<<std::endl;
			if(rootName[0]=='_'){continue;}	//Ignore comments
			this->jsonMap[rootName]=this->_parseIndex(rootName);
		}
	}catch(std::exception &e){
		std::cerr<<"DataParser::DataParser::Error loading "<<jsonDocument<<std::endl<<e.what()<<std::endl;
		std::exit(-1);
	}

}

Json::Value *DataParser::_parseFile(std::string pathName){
	Json::Value *target=new Json::Value();
	try{
		std::ifstream jsonFile(pathName);
		jsonFile>>(*target);
		FILE_LOG(logINFO)<<"Parsed"<<pathName<<std::endl;
		jsonFile.close();
		FILE_LOG(logINFO)<<"Closed"<<std::endl;
	}catch(std::exception &e){
		FILE_LOG(logERROR)<<"DataParser::_parseFile:Error loading "<<pathName<<std::endl<<e.what()<<std::endl;
		std::exit(-1);
	}
	return target;
}

Json::Value *DataParser::_parsePath(std::filesystem::path pathName){
	return _parseFile(pathName.string());
}


Json::Value *DataParser::_parseIndex(std::string indexName){
	FILE_LOG(logINFO)<<"Parsing "<<indexName<<std::endl;
	std::string configJSON;
	if(_jvIndex==NULL){return NULL;}
	try{
		std::string configFolder=(*_jvIndex)[indexName]["folder"].asString();
		std::string configFile=(*_jvIndex)[indexName]["file"].asString();
		configJSON=(_dataFolder / configFolder / configFile).string();
	}catch(std::exception &e){
		FILE_LOG(logERROR)<<"Error loading "<<indexName<<std::endl<<e.what()<<std::endl;
		std::exit(-1);
	}
	return _parseFile(configJSON);
}

Json::Value *DataParser::getJSONRoot(std::string rootName){
	return jsonMap[rootName];
}


const std::string DataParser::getDataFolder() {
	return DataParser::_dataFolder.string();
}

void DataParser::setDataFolder(const char* dataFolder) {
	std::filesystem::current_path(dataFolder);
	DataParser::_dataFolder = std::filesystem::current_path();
}

void DataParser::setDataFolder(const std::string& dataFolder) {
	std::filesystem::current_path(dataFolder);
	DataParser::_dataFolder = std::filesystem::current_path();
}

void DataParser::setDataFolder(const std::filesystem::path& folderPath) {
	std::filesystem::current_path(folderPath);
	DataParser::_dataFolder = std::filesystem::current_path();
}

DataParser::~DataParser() {
	delete _jvIndex;
}
//Statics
std::filesystem::path DataParser::_dataFolder;

} /* namespace enDJIN */

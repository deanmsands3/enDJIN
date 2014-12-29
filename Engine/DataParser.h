/*
 * DataParser.h
 *
 *  Created on: Dec 19, 2014
 *      Author: Dean
 */

#ifndef ENGINE_DATAPARSER_H_
#define ENGINE_DATAPARSER_H_
#include "../Util/Types.h"
#include <boost/filesystem.hpp>
#include <array>
#include <memory>
#include <cstdlib>
#include <string>
#include <cstring>
#include <json/json.h>
#include <iostream>
#include <Python.h>
namespace enDJIN {

class DataParser {
	Json::Value *_jvIndex;
	Json::Value *_jvConfig;
	Json::Value *_jvGameScreens;
	Json::Value *_jvActors;
	Json::Value *_parse(Json::Reader *jsonReader, boost::filesystem::path pathName);
	Json::Value *_parse(Json::Reader *jsonReader, std::string fileName);
	Json::Value *_parseFile(Json::Reader *jsonReader, std::string fileName);
	static boost::filesystem::path _dataFolder;
public:
	DataParser(const std::string &jsonDocument);
	Json::Value *getConfig();
	Json::Value *getGameScreens();
	Json::Value *getActors();
	virtual ~DataParser();
	static const std::string& getDataFolder();
	void static setDataFolder(const std::string& dataFolder);
	void static setDataFolder(const char* dataFolder);
	void static setDataFolder(const boost::filesystem::path& folderPath);
};

} /* namespace enDJIN */

#endif /* ENGINE_DATAPARSER_H_ */

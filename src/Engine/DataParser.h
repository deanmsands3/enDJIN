/*
 * DataParser.h
 *
 *  Created on: Dec 19, 2014
 *      Author: Dean
 */

#ifndef SRC_ENGINE_DATAPARSER_H_
#define SRC_ENGINE_DATAPARSER_H_
#include <unordered_map>
#include <boost/filesystem.hpp>
#include <array>
#include <memory>
#include <cstdlib>
#include <string>
#include <cstring>
#include <json/json.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <Python.h>
#include "Util/Util.h"

namespace enDJIN {

class DataParser {
	std::unordered_map<std::string, Json::Value *> jsonMap;
	Json::Value *_jvIndex;
	Json::Value *_parsePath(boost::filesystem::path pathName);
	Json::Value *_parseIndex(std::string indexName);
	Json::Value *_parseFile(std::string fileName);
	static boost::filesystem::path _dataFolder;
public:
	DataParser(const std::string &jsonDocument);
	Json::Value *getJSONRoot(std::string rootName);
	virtual ~DataParser();
	static const std::string getDataFolder();
	void static setDataFolder(const char *dataFolder);
	void static setDataFolder(const std::string& dataFolder);
	void static setDataFolder(const boost::filesystem::path& dataPath);
};

} /* namespace enDJIN */

#endif /* SRC_ENGINE_DATAPARSER_H_ */

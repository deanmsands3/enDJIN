/*
 * DataParser.h
 *
 *  Created on: Dec 19, 2014
 *      Author: Dean
 */

#ifndef ENGINE_DATAPARSER_H_
#define ENGINE_DATAPARSER_H_
#include "Types.h"
#include <array>
#include <memory>
#include <cstdlib>
#include <string>
#include <cstring>
#include <json/json.h>
#include <Python.h>

namespace enDJIN {

class DataParser {
	Json::Value *jvIndex;
	Json::Value *jvConfig;
	Json::Value *jvGameScreens;
	Json::Value *jvActors;
	Json::Value *parse(Json::Reader *jsonReader, std::string fileName);
public:
	DataParser(const std::string &jsonDocument);
	Json::Value *getConfig();
	Json::Value *getGameScreens();
	Json::Value *getActors();
	virtual ~DataParser();
};

} /* namespace enDJIN */

#endif /* ENGINE_DATAPARSER_H_ */

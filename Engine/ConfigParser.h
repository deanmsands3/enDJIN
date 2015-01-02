/*
 * ConfigParser.h
 *
 *  Created on: Aug 25, 2014
 *      Author: Dean
 */

#ifndef CONFIGPARSER_H_
#define CONFIGPARSER_H_
#define SCREEN_WIDTH	1600
#define SCREEN_HEIGHT	900
#include "../Util/Types.h"
#include <array>
#include <memory>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <stdexcept>
#include <json/json.h>
#include <Python.h>
#include "KeyMappings.h"

namespace enDJIN{
	class ConfigParser {
	Json::Value *config;
	public:
		ConfigParser(const Json::Value *newConfig);
		virtual ~ConfigParser();
		const Json::Value *getConfig() const;
		KeyMappings *generateKeyMap();
		Json::Value getItem(std::string itemName, int index);
	};
};
#endif /* CONFIGPARSER_H_ */

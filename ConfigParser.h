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

#include <array>
#include <memory>
#include <cstdlib>
#include <string>
#include <cstring>
#include <Python.h>
#include <json/json.h>
namespace enDJIN{
	class ConfigParser {
	Json::Value config;
	public:
		ConfigParser(const std::string &jsonDocument);
		virtual ~ConfigParser();
	const Json::Value *getConfig() const;
};
};
#endif /* CONFIGPARSER_H_ */

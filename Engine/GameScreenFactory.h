/*
 * GameScreenFactory.h
 *
 *  Created on: Nov 25, 2014
 *      Author: dean
 */

#ifndef GAMESCREENFACTORY_H_
#define GAMESCREENFACTORY_H_
#include "ConfigParser.h"
namespace enDJIN {

class GameScreenFactory {
	Json::Value *jData;
public:
	GameScreenFactory(Json::Value *JV);
	virtual ~GameScreenFactory();
};

} /* namespace enDJIN */

#endif /* GAMESCREENFACTORY_H_ */
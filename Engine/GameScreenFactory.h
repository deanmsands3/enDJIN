/*
 * GameScreenFactory.h
 *
 *  Created on: Nov 25, 2014
 *      Author: dean
 */

#ifndef GAMESCREENFACTORY_H_
#define GAMESCREENFACTORY_H_
#include "ConfigParser.h"
#include "GameScreen.h"
#include <string>
namespace enDJIN {

class GameScreenFactory {
	Json::Value *jData;
public:
	GameScreenFactory(Json::Value *JV);
	virtual ~GameScreenFactory();
	GameScreen *getGameScreen(std::string name, sf::RenderWindow *window, KeyMappings *keyMap);
	GameScreen *getInitialGameScreen(sf::RenderWindow *window, KeyMappings *keyMap);
};

} /* namespace enDJIN */

#endif /* GAMESCREENFACTORY_H_ */

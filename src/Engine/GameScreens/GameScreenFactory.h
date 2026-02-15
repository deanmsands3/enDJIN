/*
 * GameScreenFactory.h
 *
 *  Created on: Nov 25, 2014
 *      Author: dean
 */

#ifndef GAMESCREENFACTORY_H_
#define GAMESCREENFACTORY_H_
#include "../../Util/Util.h"
#include <unordered_map>
#include "../ConfigParser.h"
#include "GameScreen.h"
#include "MenuScreen.h"
#include "PlayScreen.h"
#include "SplashScreen.h"
#include "LoadingScreen.h"

namespace enDJIN {

class GameScreenFactory {
	Json::Value *jData;
	GameScreenFactory(Json::Value *JV);
	std::unordered_map<std::string, GameScreenCtor>gameScreenCtorMap;
	static GameScreenFactory *thisInstance;
public:
	static GameScreenFactory *getInstance(Json::Value *JV);
	static GameScreenFactory *getInstance();
	virtual ~GameScreenFactory();
	GameScreen *getGameScreen(std::string name, sf::RenderWindow *window, KeyMappings *keyMap);
	GameScreen *getInitialGameScreen(sf::RenderWindow *window, KeyMappings *keyMap);
};

} /* namespace enDJIN */

#endif /* GAMESCREENFACTORY_H_ */

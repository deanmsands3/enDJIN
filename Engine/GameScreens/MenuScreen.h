/*
 * MenuScreen.h
 *
 *  Created on: Jan 1, 2015
 *      Author: Dean
 */

#ifndef ENGINE_GAMESCREENS_MENUSCREEN_H_
#define ENGINE_GAMESCREENS_MENUSCREEN_H_

#include "GameScreen.h"

namespace enDJIN {

class MenuScreen: public GameScreen {
public:
	MenuScreen(sf::RenderWindow *window, KeyMappings *keyMap, Json::Value *JV);
	virtual ~MenuScreen();
	static GameScreen* newGameScreen(sf::RenderWindow *window, KeyMappings *keyMap, Json::Value *JV);
};

} /* namespace enDJIN */

#endif /* ENGINE_GAMESCREENS_MENUSCREEN_H_ */

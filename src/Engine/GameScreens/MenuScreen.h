/*
 * MenuScreen.h
 *
 *  Created on: Jan 1, 2015
 *      Author: Dean
 */

#ifndef SRC_ENGINE_GAMESCREENS_MENUSCREEN_H_
#define SRC_ENGINE_GAMESCREENS_MENUSCREEN_H_

#include "GameScreen.h"

namespace enDJIN {

class MenuScreen: public GameScreen {
public:
	MenuScreen(sf::RenderWindow *window, KeyMappings *keyMap, Json::Value *JV);
	virtual ~MenuScreen();
	static GameScreen* newGameScreen(sf::RenderWindow *window, KeyMappings *keyMap, Json::Value *JV);
	void Show();
};

} /* namespace enDJIN */

#endif /* SRC_ENGINE_GAMESCREENS_MENUSCREEN_H_ */

/*
 * LoadingScreen.h
 *
 *  Created on: Jan 5, 2015
 *      Author: Dean
 */

#ifndef SRC_ENGINE_GAMESCREENS_LOADINGSCREEN_H_
#define SRC_ENGINE_GAMESCREENS_LOADINGSCREEN_H_

#include "GameScreen.h"

namespace enDJIN {

class LoadingScreen: public GameScreen {
public:
	LoadingScreen(sf::RenderWindow *window, KeyMappings *keyMap, Json::Value *JV);
	virtual ~LoadingScreen();
	virtual void Show();
	static GameScreen* newGameScreen(sf::RenderWindow *window, KeyMappings *keyMap, Json::Value *JV);

};

} /* namespace enDJIN */

#endif /* SRC_ENGINE_GAMESCREENS_LOADINGSCREEN_H_ */

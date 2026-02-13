/*
 * PlayScreen.h
 *
 *  Created on: Jan 3, 2015
 *      Author: Dean
 */

#ifndef SRC_ENGINE_GAMESCREENS_PLAYSCREEN_H_
#define SRC_ENGINE_GAMESCREENS_PLAYSCREEN_H_

#include "GameScreen.h"

namespace enDJIN {

class PlayScreen: public GameScreen {
public:
	PlayScreen(sf::RenderWindow *window, KeyMappings *keyMap, Json::Value *JV);
	virtual ~PlayScreen();
	virtual void Show();
	static GameScreen* newGameScreen(sf::RenderWindow *window, KeyMappings *keyMap, Json::Value *JV);

	void playerMoves(void *direction);
	void playerDies(void *dummy);
	void playerRises(void *dummy);
};

} /* namespace enDJIN */

#endif /* SRC_ENGINE_GAMESCREENS_PLAYSCREEN_H_ */

/*
 * LoadingScreen.cpp
 *
 *  Created on: Jan 5, 2015
 *      Author: Dean
 */

#include "LoadingScreen.h"

namespace enDJIN {


LoadingScreen::LoadingScreen(sf::RenderWindow* window, KeyMappings* keyMap,
		Json::Value* JV):GameScreen(window, keyMap, JV) {
}

LoadingScreen::~LoadingScreen() {
	// TODO Auto-generated destructor stub
}

void LoadingScreen::Show() {
	renderWin->display();
}

GameScreen* LoadingScreen::newGameScreen(sf::RenderWindow* window,
		KeyMappings* keyMap, Json::Value* JV) {
	return new LoadingScreen(window, keyMap, JV);
}

}; /* namespace enDJIN */

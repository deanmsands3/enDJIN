/*
 * MenuScreen.cpp
 *
 *  Created on: Jan 1, 2015
 *      Author: Dean
 */

#include "MenuScreen.h"

namespace enDJIN {

MenuScreen::MenuScreen(sf::RenderWindow *window, KeyMappings *keyMap, Json::Value *JV):
	GameScreen(window, keyMap, JV) {


}

MenuScreen::~MenuScreen() {
	// TODO Auto-generated destructor stub
}
GameScreen* MenuScreen::newGameScreen(sf::RenderWindow *window, KeyMappings *keyMap, Json::Value *JV){
	return new MenuScreen(window, keyMap, JV);
}
} /* namespace enDJIN */

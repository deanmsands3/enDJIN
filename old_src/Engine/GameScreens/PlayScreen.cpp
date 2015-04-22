/*
 * PlayScreen.cpp
 *
 *  Created on: Jan 3, 2015
 *      Author: Dean
 */

#include "PlayScreen.h"

namespace enDJIN {

PlayScreen::PlayScreen(sf::RenderWindow* window, KeyMappings* keyMap, Json::Value *JV):
		GameScreen(window, keyMap, JV) {
	// TODO Auto-generated constructor stub

}
void PlayScreen::Show(){
	renderWin->display();
}

PlayScreen::~PlayScreen() {
	// TODO Auto-generated destructor stub
}
GameScreen* PlayScreen::newGameScreen(sf::RenderWindow* window,KeyMappings* keyMap, Json::Value *JV){
	return new PlayScreen(window, keyMap, JV);
}


void PlayScreen::playerMoves(void* direction) {
	if(Player::getInstance()==nullptr) throw std::runtime_error("No Player Object.");
}

void PlayScreen::playerDies(void* dummy) {

}

void PlayScreen::playerRises(void* dummy) {
}

}
;
/* namespace enDJIN */

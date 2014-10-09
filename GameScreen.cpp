/*
 * GameState.cpp
 *
 *  Created on: Sep 12, 2014
 *      Author: Dean
 */

#include "GameScreen.h"
namespace enDJIN{
	GameScreen::GameScreen() {
		// TODO Auto-generated constructor stub
		EventMap = new std::map<sf::Event,voidFuncPtr>();

	}

	GameScreen::~GameScreen() {
		// TODO Auto-generated destructor stub
	}
	GameScreen *GameScreen::updateGameScreen(){return this;}
	void GameScreen::Show(sf::RenderWindow& window){}

}

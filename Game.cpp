/*
 * Game.cpp
 *
 *  Created on: Aug 24, 2014
 *      Author: Dean
 */

#include "Game.h"
#include "GameScreen.h"
namespace enDJIN{
Game::Game(const std::string &index_json) {
	// Create SFML's window.
	config = new ConfigParser(index_json);
	renderWin=new sf::RenderWindow( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ), "Hello world!" );
	//Determine which gamestate is active
	//Load gamestate
	GameScreen *currentGS=new GameScreen(renderWin);
	while(currentGS=currentGS->updateGameScreen()){}
}

Game::~Game() {
	renderWin->close();
}
};

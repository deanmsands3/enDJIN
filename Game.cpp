/*
 * Game.cpp
 *
 *  Created on: Aug 24, 2014
 *      Author: Dean
 */

#include "Game.h"
Game::Game(const std::string &index_json) {
	// Create SFML's window.
	config = new ConfigParser(index_json);
	renderWin=new sf::RenderWindow( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ), "Hello world!" );

}

Game::~Game() {
	renderWin->close();
}


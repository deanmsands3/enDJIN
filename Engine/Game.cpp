/*
 * Game.cpp
 *
 *  Created on: Aug 24, 2014
 *      Author: Dean
 */

#include "Game.h"

namespace enDJIN{
Game::Game(const std::string &index_json) {
	setup(index_json);
	loop();
}

Game::~Game() {
	delete gsf;
	renderWin->close();
	delete renderWin;
	delete config;
	delete dataparser;
}

void Game::setup(const std::string &index_json){
	DataParser::setDataFolder(std::string("./Data"));
	dataparser=new DataParser(index_json);
	// Initialize the Config Parser
	config = new ConfigParser(dataparser->getConfig());
	KeyMappings *keyMap=config->generateKeyMap();
	// Create SFML's window.
	renderWin=new sf::RenderWindow(
			sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ),
			"enDJIN"
			);
	//Determine which gamestate is active
	gsf=new GameScreenFactory(dataparser->getGameScreens());
	//Load gamestate
	currentGS=gsf->getInitialGameScreen(renderWin,keyMap);
	delete keyMap;
}
void Game::loop(){

	while((currentGS=currentGS->updateGameScreen())){}
}

};

/*
 * Game.cpp
 *
 *  Created on: Aug 24, 2014
 *      Author: Dean
 */

#include "Game.h"
#include "GameScreen.h"
#include "GameScreenFactory.h"
namespace enDJIN{
Game::Game(const std::string &index_json) {
	// Initialize the Config Parser
	config = new ConfigParser(index_json);
	KeyMappings *keyMap=config->generateKeyMap();
	// Create SFML's window.
	renderWin=new sf::RenderWindow( sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ), "Hello world!" );
	Json::Value jvGameScreens=(*config->getConfig())["gamescreens"];
	//Determine which gamestate is active
	gsf=new GameScreenFactory(&jvGameScreens);
	//Load gamestate
	GameScreen *currentGS=gsf->getInitialGameScreen(renderWin,keyMap);
	while(currentGS=currentGS->updateGameScreen()){}
}

Game::~Game() {
	renderWin->close();
}
};

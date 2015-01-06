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

const Game* Game::getInstance() {
	if(Game::_instance==nullptr) throw std::runtime_error("Game Object not initialized!");
	return (const Game*)Game::_instance;
}

Game* Game::init(const std::string& index_json) {
	if(Game::_instance==nullptr){Game::_instance=new Game(index_json);}
	return Game::_instance;
}

Game::~Game() {
	delete gsf;
	renderWin->close();
	delete renderWin;
	delete config;
	delete dataparser;
}

void Game::setup(const std::string &index_json){
	DataParser::setDataFolder("Data");
	dataparser=new DataParser(index_json);
	// Initialize the Config Parser
	config = new ConfigParser(dataparser->getJSONRoot("config"));
	KeyMappings *keyMap=config->generateKeyMap();
	// Create SFML's window.
	renderWin=new sf::RenderWindow(
			sf::VideoMode( SCREEN_WIDTH, SCREEN_HEIGHT ),
			"enDJIN"
			);
	//Determine which gamestate is active
	GameScreen::setDataPath("GameScreens");
//	GameScreen::setDataPath();

	gsf=GameScreenFactory::getInstance(dataparser->getJSONRoot("gamescreens"));

	//Load gamestate
	currentGameScreen=gsf->getInitialGameScreen(renderWin,keyMap);
	delete keyMap;
}
void Game::loop(){
	bool running=true;
	while(running){
		while(currentGameScreen->updateGameScreen()){}
		GameScreen *oldGameScreen=currentGameScreen;
		currentGameScreen=oldGameScreen->getNextGameScreen();
		delete oldGameScreen;
		running =(currentGameScreen!=nullptr);
	}
}

Game* Game::_instance=nullptr;
};

/*
 * GameScreenFactory.cpp
 *
 *  Created on: Nov 25, 2014
 *      Author: dean
 */

#include "GameScreenFactory.h"

namespace enDJIN {

GameScreenFactory::GameScreenFactory(Json::Value *JV):jData(JV) {
	// TODO Auto-generated constructor stub

}

GameScreenFactory::~GameScreenFactory() {
	// TODO Auto-generated destructor stub
}
GameScreen* GameScreenFactory::getGameScreen(std::string name, sf::RenderWindow *window, KeyMappings *keyMap){
	Json::Value *gameScreenJSON=new Json::Value();
	jData->get(name,gameScreenJSON);
	return new GameScreen(window, keyMap, gameScreenJSON);
}
GameScreen* GameScreenFactory::getInitialGameScreen(sf::RenderWindow *window, KeyMappings *keyMap){

}

} /* namespace enDJIN */

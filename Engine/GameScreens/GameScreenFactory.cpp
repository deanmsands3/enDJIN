/*
 * GameScreenFactory.cpp
 *
 *  Created on: Nov 25, 2014
 *      Author: dean
 */

#include "GameScreenFactory.h"
#include "Util/Log.h"
#include <iostream>
namespace enDJIN {

GameScreenFactory::GameScreenFactory(Json::Value *JV):jData(JV) {
	gameScreenCtorMap["game"]=&GameScreen::newGameScreen;
	gameScreenCtorMap["splashscreen"]=&SplashScreen::newGameScreen;
	gameScreenCtorMap["menuscreen"]=&MenuScreen::newGameScreen;
	FILE_LOG(logINFO)<<"GSF Constructed"<<std::endl;
}

GameScreenFactory::~GameScreenFactory() {
	delete jData;
}

GameScreen* GameScreenFactory::getGameScreen(std::string name, sf::RenderWindow *window, KeyMappings *keyMap){
	try{
		Json::Value *gameScreenJSON=new Json::Value((*jData)[name]);
		std::string gameScreenType;
		gameScreenType=(*gameScreenJSON)["type"].asString();
		FILE_LOG(logINFO)<<"GSF:getGameScreen:"<<"Name:"<<name<<":"<<gameScreenType<<std::endl;
		GameScreenCtor thisGameScreenCtor=gameScreenCtorMap[gameScreenType];
		return thisGameScreenCtor(window, keyMap, gameScreenJSON);

	}catch(std::exception &e){
		FILE_LOG(logERROR)<<e.what();
		std::exit(-1);
	}
}
GameScreen* GameScreenFactory::getInitialGameScreen(sf::RenderWindow *window, KeyMappings *keyMap){
	return GameScreenFactory::getGameScreen("start", window, keyMap);
}

GameScreenFactory* GameScreenFactory::getInstance(Json::Value *JV){
	//Return thisInstance if it exists, create a new one otherwise.
	if(GameScreenFactory::thisInstance!=NULL){return GameScreenFactory::thisInstance;}
	GameScreenFactory::thisInstance = new GameScreenFactory(JV);
	return GameScreenFactory::thisInstance;
}

GameScreenFactory* GameScreenFactory::getInstance(){
	if(GameScreenFactory::thisInstance!=NULL){return GameScreenFactory::thisInstance;}
	throw std::runtime_error("The singleton does not exist, and the JSON is not specified");
}

GameScreenFactory *GameScreenFactory::thisInstance=NULL;
} /* namespace enDJIN */

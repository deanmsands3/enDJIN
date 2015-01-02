/*
 * GameState.cpp
 *
 *  Created on: Sep 12, 2014
 *      Author: Dean
 */

#include "GameScreen.h"

#include <iostream>
namespace enDJIN{
	GameScreen::GameScreen(sf::RenderWindow *window, KeyMappings *keyMap, Json::Value *JV) {
		renderWin=window;
		jData=JV;
		std::cout<<*jData<<std::endl;
		// TODO Auto-generated constructor stub
		eventMap = new std::map<sf::Event,voidFuncPtr>();
		entityMap = new std::map<uint64_t,Entity*>();
		actionEffectMap=new std::unordered_map<std::string,voidFuncPtr>();
		registerKeyMappings(keyMap);
	}

	GameScreen::~GameScreen() {
		delete entityMap;
		delete eventMap;
		delete actionEffectMap;
		delete jData;
	}
	GameScreen *GameScreen::updateGameScreen(){
		this->Show();
		this->processEntities();
		return this->processEvents();
	}
	void GameScreen::Show(){
		// Rendering.
		renderWin->clear();
		renderWin->display();
	}
	GameScreen* GameScreen::processEntities() {
		for (const auto& thisEntity : *entityMap) {
		    thisEntity.second->update();
		}
		return this;
	}

	GameScreen* GameScreen::processEvents() {
		sf::Event event;
		while( renderWin->pollEvent( event ) ) {
			/*

			TO DO:
			HANDLE THE EVENT

			*/

			// If window is about to be closed, leave program.
			if( event.type == sf::Event::Closed ) {
				renderWin->close();
				return NULL;
			}
		}
		return this;
	}

	const sf::RenderWindow*& GameScreen::getRenderWin() const {
		return (const sf::RenderWindow*&)renderWin;
	}

	void GameScreen::setRenderWin(const sf::RenderWindow*& renderWin) {
		this->renderWin = (sf::RenderWindow*)renderWin;
	}

	std::unordered_map<std::string, voidFuncPtr>* GameScreen::getActionEffectMap() {
		return this->actionEffectMap;
	}
	std::map<uint64_t, Entity*>* GameScreen::getEntityMap(){
		return this->entityMap;
	}

	void GameScreen::registerKeyMappings(KeyMappings* keyMap) {

	}

	void GameScreen::registerActionMappings() {

	}

	std::map<sf::Event, voidFuncPtr>* GameScreen::getEventMap(){
		return this->eventMap;
	}
	GameScreen* GameScreen::newGameScreen(sf::RenderWindow *window, KeyMappings *keyMap, Json::Value *JV){
		return new GameScreen(window, keyMap, JV);
	}
}	//Namespace enDJIN


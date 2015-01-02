/*
 * GameState.h
 *
 *  Created on: Sep 12, 2014
 *      Author: Dean
 */

#ifndef GAMESCREEN_H_
#define GAMESCREEN_H_
#include "Util/Types.h"
#include <SFML/Graphics.hpp>
#include <map>
#include <unordered_map>
#include "Engine/ConfigParser.h"
#include "Engine/KeyMappings.h"
#include "Entities/Entity.h"
namespace enDJIN{
	class GameScreen {
	protected:
		sf::RenderWindow *renderWin;
		std::map<sf::Event, voidFuncPtr> *eventMap;
		std::map<uint64_t, Entity*> *entityMap;
		std::unordered_map<std::string,voidFuncPtr> *actionEffectMap;
		Json::Value *jData;
	public:
		static GameScreen* newGameScreen(sf::RenderWindow *window, KeyMappings *keyMap, Json::Value *JV);
		GameScreen(sf::RenderWindow *window, KeyMappings *keyMap, Json::Value *JV);
		virtual ~GameScreen();
		GameScreen *updateGameScreen();
		GameScreen *processEntities();
		GameScreen *processEvents();
		virtual void Show();
		const sf::RenderWindow*& getRenderWin() const;
		void setRenderWin(const sf::RenderWindow*& renderWin);
		void registerKeyMappings(KeyMappings *keyMap);
		void registerActionMappings();
		std::unordered_map<std::string, voidFuncPtr>* getActionEffectMap();
		std::map<uint64_t, Entity*>* getEntityMap();
		std::map<sf::Event, voidFuncPtr>* getEventMap();
	};//GameScreen
	typedef GameScreen* (*GameScreenCtor)(sf::RenderWindow *window, KeyMappings *keyMap, Json::Value *JV);

};//enDJIN
#endif /* GAMESCREEN_H_ */

/*
 * GameState.h
 *
 *  Created on: Sep 12, 2014
 *      Author: Dean
 */

#ifndef GAMESCREEN_H_
#define GAMESCREEN_H_
#include <json/json.h>
#include <boost/lockfree/queue.hpp>
#include <boost/filesystem.hpp>
#include <SFML/Graphics.hpp>
#include <map>
#include <unordered_map>

#include "Util/Util.h"
#include "Entities/Entity.h"
#include "Engine/ConfigParser.h"
#include "Engine/Events/Events.h"
#include "Entities/Entity.h"

namespace enDJIN{
	class GameScreen {
	protected:
		boost::lockfree::queue<enDJIN::Event, boost::lockfree::capacity<32>> _messagePump;
		static boost::filesystem::path _dataPath;
		sf::RenderWindow *renderWin;
		std::map<sf::Event, voidFuncPtr> *eventMap;
		std::map<uint64_t, Entity*> *entityMap;
		std::unordered_map<std::string,voidFuncPtr> *actionEffectMap;
		Json::Value *jData;
		GameScreen *_nextGameScreen;
		void processWindowEvents();
	public:
		static GameScreen* newGameScreen(sf::RenderWindow *window, KeyMappings *keyMap, Json::Value *JV);
		GameScreen(sf::RenderWindow *window, KeyMappings *keyMap, Json::Value *JV);
		virtual ~GameScreen();
		virtual GameScreen *updateGameScreen();
		virtual GameScreen *processEntities();
		virtual GameScreen *processEvents();
		virtual void Show() const;
		const sf::RenderWindow*& getRenderWin() const;
		void setRenderWin(const sf::RenderWindow*& renderWin);
		void registerKeyMappings(KeyMappings *keyMap);
		void registerActionMappings();
		std::unordered_map<std::string, voidFuncPtr>* getActionEffectMap();
		std::map<uint64_t, Entity*>* getEntityMap();
		std::map<sf::Event, voidFuncPtr>* getEventMap();
		static const boost::filesystem::path& getDataPath();
		static void setDataPath(const boost::filesystem::path &dataPath);
		GameScreen* getNextGameScreen();
		void setNextGameScreen(GameScreen* nextGameScreen);
};
//GameScreen
	typedef GameScreen* (*GameScreenCtor)(sf::RenderWindow *window, KeyMappings *keyMap, Json::Value *JV);

};//enDJIN
#endif /* GAMESCREEN_H_ */

/*
 * GameState.h
 *
 *  Created on: Sep 12, 2014
 *      Author: Dean
 */

#ifndef GAMESCREEN_H_
#define GAMESCREEN_H_
#include <SFML/Graphics.hpp>
#include <map>
#include "ConfigParser.h"
#include "Types.h"
namespace enDJIN{
	class GameScreen {
		std::map<sf::Event, voidFuncPtr> *EventMap;
	public:
		GameScreen();
		virtual ~GameScreen();
		GameScreen *updateGameScreen();
		virtual void Show(sf::RenderWindow& window);
	};
};
#endif /* GAMESCREEN_H_ */

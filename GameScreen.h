/*
 * GameState.h
 *
 *  Created on: Sep 12, 2014
 *      Author: Dean
 */

#ifndef GAMESCREEN_H_
#define GAMESCREEN_H_
#include <SFML/Graphics.hpp>
#include "ConfigParser.h"
namespace enDJIN{
	class GameScreen {
	public:
		GameScreen();
		virtual ~GameScreen();
		GameScreen *updateGameScreen();
		virtual void Show(sf::RenderWindow& window);
	};
};
#endif /* GAMESCREEN_H_ */

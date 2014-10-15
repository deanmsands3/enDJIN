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
#include "Entity.h"
namespace enDJIN{
	class GameScreen {
		sf::RenderWindow *renderWin;
		std::map<sf::Event, voidFuncPtr> *EventMap;
		std::map<uint64_t, Entity*> *EntityMap;

	public:
		GameScreen(sf::RenderWindow *window);
		virtual ~GameScreen();
		GameScreen *updateGameScreen();
		GameScreen *processEntities();
		GameScreen *processEvents();
		virtual void Show();
		const sf::RenderWindow*& getRenderWin() const;
		void setRenderWin(const sf::RenderWindow*& renderWin);
};
};
#endif /* GAMESCREEN_H_ */

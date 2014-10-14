/*
 * GameState.cpp
 *
 *  Created on: Sep 12, 2014
 *      Author: Dean
 */

#include "GameScreen.h"
namespace enDJIN{
	GameScreen::GameScreen(sf::RenderWindow *window) {
		renderWin=window;
		// TODO Auto-generated constructor stub
		EventMap = new std::map<sf::Event,voidFuncPtr>();

	}

	GameScreen::~GameScreen() {
		// TODO Auto-generated destructor stub
	}
	GameScreen *GameScreen::updateGameScreen(){
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

		Show();
		return this;
	}
	void GameScreen::Show(){
		// Rendering.
		renderWin->clear();
		renderWin->display();


	}

	const sf::RenderWindow*& GameScreen::getRenderWin() const {
		return (const sf::RenderWindow*&)renderWin;
	}

	void GameScreen::setRenderWin(const sf::RenderWindow*& renderWin) {
		this->renderWin = (sf::RenderWindow*)renderWin;
	}
}


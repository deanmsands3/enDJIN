/*
 * SplashScreen.cpp
 *
 *  Created on: Sep 22, 2014
 *      Author: Dean
 */

#include "SplashScreen.h"

namespace enDJIN {
	SplashScreen::SplashScreen(sf::RenderWindow *window, KeyMappings *keyMap, Json::Value *JV):
		GameScreen(window, keyMap, JV) {
		std::string imageName;
		imageName=(*jData)["splash"].asString();
		sf::Texture _texture;
		if(_texture.loadFromFile(imageName) != true)
		{
			return;
		}

		_sprite.setTexture(_texture);


	}

	SplashScreen::~SplashScreen() {
		// TODO Auto-generated destructor stub
	}
	void SplashScreen::Show(sf::RenderWindow& window){
		window.draw(_sprite);
		window.display();
	}
	GameScreen* SplashScreen::newGameScreen(sf::RenderWindow *window, KeyMappings *keyMap, Json::Value *JV){
		return new GameScreen(window, keyMap, JV);
	}

} /* namespace enDJIN */

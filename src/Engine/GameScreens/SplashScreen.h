/*
 * SplashScreen.h
 *
 *  Created on: Sep 22, 2014
 *      Author: Dean
 */

#ifndef SPLASHSCREEN_H_
#define SPLASHSCREEN_H_
#include "GameScreen.h"
namespace enDJIN {

class SplashScreen: public GameScreen {
	sf::Sprite _sprite;
	sf::Texture _texture;
public:
	SplashScreen(sf::RenderWindow *window, KeyMappings *keyMap, Json::Value *JV);
	virtual ~SplashScreen();
	virtual void Show();
	static GameScreen* newGameScreen(sf::RenderWindow *window, KeyMappings *keyMap, Json::Value *JV);
};

} /* namespace enDJIN */

#endif /* SPLASHSCREEN_H_ */

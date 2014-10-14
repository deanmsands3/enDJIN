/*
 * SplashScreen.h
 *
 *  Created on: Sep 22, 2014
 *      Author: Dean
 */

#ifndef SPLASHSCREEN_H_
#define SPLASHSCREEN_H_

#include "GameScreen.h"
#include "ConfigParser.h"
#include <json/json.h>
namespace enDJIN {

class SplashScreen: public GameScreen {
	sf::Sprite _sprite;
public:
	SplashScreen(sf::RenderWindow *window, Json::Value *JV);
	virtual ~SplashScreen();
	virtual void Show(sf::RenderWindow& window);
};

} /* namespace enDJIN */

#endif /* SPLASHSCREEN_H_ */

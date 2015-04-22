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
	imageName =
			(
					GameScreen::getDataPath() /				//Path to data
					(*jData)["splash"].asString()			//Name of image file
			).string();
	FILE_LOG(logINFO)<<"SplashScreen:"<<imageName<<std::endl;
	if(_texture.loadFromFile(imageName) != true)
	{
		throw std::runtime_error("Could not load asset.");
	}

	_sprite.setTexture(_texture);
	FILE_LOG(logINFO)<<"Splash Screen Initialized"<<std::endl;

}

SplashScreen::~SplashScreen() {
	// TODO Auto-generated destructor stub
}
void SplashScreen::Show(){
	static bool thisFlag=false;
	if(thisFlag==false){
		thisFlag=true;
		FILE_LOG(logINFO)<<"Splash shown"<<std::endl;
	}
	renderWin->draw(_sprite);
	renderWin->display();
}
GameScreen* SplashScreen::newGameScreen(sf::RenderWindow *window, KeyMappings *keyMap, Json::Value *JV){
	return new SplashScreen(window, keyMap, JV);
}

} /* namespace enDJIN */

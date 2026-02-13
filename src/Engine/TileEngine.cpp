/*
 * TileEngine.cpp
 *
 *  Created on: Sep 15, 2014
 *      Author: Dean
 */

#include "TileEngine.h"

namespace enDJIN {

TileEngine::TileEngine() {
	// TODO Auto-generated constructor stub

}

TileEngine::~TileEngine() {
	// TODO Auto-generated destructor stub
}
uint32_t TileEngine::registerNewSprite(std::string spriteName, std::string textureName, int x,int y, int w, int h){

	sf::Texture thisTexture=TextureMap[textureName];
	sf::IntRect thisRect(x,y,w,h);
	sf::Sprite *thisSprite=new sf::Sprite(thisTexture, thisRect);

	SpriteMap[spriteName]=thisSprite;
	SpriteArray.push_back(thisSprite);
	return SpriteArray.size()-1;
}
sf::Sprite *TileEngine::getSprite(unsigned long index){
	return SpriteArray[index];
}
} /* namespace enDJIN */

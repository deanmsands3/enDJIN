/*
 * TileEngine.h
 *
 *  Created on: Sep 15, 2014
 *      Author: Dean
 */

#ifndef TILE_H_
#define TILE_H_
#include "../Util/Util.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include <vector>
#include <json/json.h>

namespace enDJIN {

class TileEngine {
	std::unordered_map<std::string, sf::Texture> TextureMap;
	std::unordered_map<std::string, sf::Sprite*> SpriteMap;
	std::vector<sf::Sprite*> SpriteArray;
public:
	uint32_t registerNewSprite(std::string spriteName, std::string textureName,  int x,int y, int w, int h);
	TileEngine();
	virtual ~TileEngine();
	sf::Sprite *getSprite(unsigned long index);
};

} /* namespace enDJIN */

#endif /* TILE_H_ */

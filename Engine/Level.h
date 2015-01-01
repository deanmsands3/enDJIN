/*
 * Level.h
 *
 *  Created on: Sep 15, 2014
 *      Author: Dean
 */

#ifndef LEVEL_H_
#define LEVEL_H_
#include "../Util/Types.h"
#include <SFML/Graphics.hpp>
#include <unordered_map>
namespace enDJIN {

class Level {
std::unordered_map<unsigned int, sf::Sprite*> spriteMap;
public:
	Level();
	virtual ~Level();
};

} /* namespace enDJIN */

#endif /* LEVEL_H_ */

/*
 * Level.h
 *
 *  Created on: Sep 15, 2014
 *      Author: Dean
 */

#ifndef LEVEL_H_
#define LEVEL_H_
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "Engine/Events/Events.h"
#include "Util/Util.h"
namespace enDJIN {

class Level {
std::unordered_map<unsigned int, sf::Sprite*> _spriteMap;
std::vector< std::vector <unsigned int> > _levelData;
std::unordered_map<std::string, enDJIN::Event> _eventMap;

public:
	Level();
	virtual ~Level();
};

} /* namespace enDJIN */

#endif /* LEVEL_H_ */

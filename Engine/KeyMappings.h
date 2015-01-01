/*
 * KeyMappings.h
 *
 *  Created on: Oct 9, 2014
 *      Author: Dean.Sands
 */

#ifndef KEYMAPPINGS_H_
#define KEYMAPPINGS_H_
#include "../Util/Types.h"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <unordered_map>
#include <exception>
namespace enDJIN {

class KeyMappings {
	std::unordered_map<unsigned int,std::string> keyActionMap;
	std::unordered_map<std::string,voidFuncPtr> *actionEffectMap;
	std::unordered_map<unsigned int,voidFuncPtr> keyEffectMap;
public:
	KeyMappings();
	virtual ~KeyMappings();
	bool map_key(sf::Keyboard::Key keyPressed,std::string newEventName);
};

} /* namespace enDJIN */

#endif /* KEYMAPPINGS_H_ */

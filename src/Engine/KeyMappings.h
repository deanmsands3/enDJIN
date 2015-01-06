/*
 * KeyMappings.h
 *
 *  Created on: Oct 9, 2014
 *      Author: Dean.Sands
 */

#ifndef KEYMAPPINGS_H_
#define KEYMAPPINGS_H_
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <unordered_map>
#include <exception>

#include "Util/Util.h"
namespace enDJIN {

class KeyMappings {
	std::unordered_map<unsigned int,std::string> keyActionMap;
	std::unordered_map<std::string,TCallBack> *actionEffectMap;
	std::unordered_map<unsigned int,TCallBack> keyEffectMap;
public:
	KeyMappings();
	virtual ~KeyMappings();
	bool map_key(sf::Keyboard::Key keyPressed,std::string newEventName);
};

} /* namespace enDJIN */

#endif /* KEYMAPPINGS_H_ */

/*
 * KeyMappings.h
 *
 *  Created on: Oct 9, 2014
 *      Author: Dean.Sands
 */

#ifndef KEYMAPPINGS_H_
#define KEYMAPPINGS_H_
#include <SFML/System.hpp>
#include <unordered_map>
namespace enDJIN {

class KeyMappings {
	std::unordered_map<std::string,sf::Event> key_bindings;
public:
	KeyMappings();
	virtual ~KeyMappings();
	bool add_key(std::string new_key,sf::Event new_event);
};

} /* namespace enDJIN */

#endif /* KEYMAPPINGS_H_ */

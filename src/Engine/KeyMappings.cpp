/*
 * KeyMappings.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: Dean.Sands
 */

#include "KeyMappings.h"

namespace enDJIN {

KeyMappings::KeyMappings() {
	// TODO Auto-generated constructor stub

}

KeyMappings::~KeyMappings() {
	keyActionMap.clear();
	keyEffectMap.clear();
}

bool KeyMappings::map_key(sf::Keyboard::Key keyPressed, std::string newEventName){
	keyActionMap[(unsigned int)keyPressed]=newEventName;
	try{
		voidFuncPtr thisFunction=(*actionEffectMap)[newEventName];
		keyEffectMap[(unsigned int)keyPressed]=thisFunction;
	}catch(std::exception &e){

		return false;
	}
	return true;
}

} /* namespace enDJIN */
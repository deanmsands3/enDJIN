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
	// TODO Auto-generated destructor stub
}

bool KeyMappings::map_key(sf::Keyboard::Key keyPressed, std::string newEventName){
	keyActionMap[(unsigned int)keyPressed]=newEventName;
//	try{
//		voidFuncPtr thisFunction=(*actionEffectMap)[newEventName];
//		keyEffectMap[(unsigned int)keyPressed]=thisFunction;
//	}catch(std::exception &e){
//
//	}
}

} /* namespace enDJIN */

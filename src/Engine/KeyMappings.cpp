/*
 * KeyMappings.cpp
 *
 *  Created on: Oct 9, 2014
 *      Author: Dean.Sands
 */

#include "KeyMappings.h"

namespace enDJIN {

KeyMappings::KeyMappings() {
	actionEffectMap=new std::unordered_map<std::string,TCallBack>();

}

KeyMappings::~KeyMappings() {
	keyActionMap.clear();
	keyEffectMap.clear();
}

bool KeyMappings::map_key(sf::Keyboard::Key keyPressed, std::string newEventName){
	keyActionMap[(unsigned int)keyPressed]=newEventName;
	try{
		TCallBack thisFunction=(*actionEffectMap)[newEventName];
		keyEffectMap[(unsigned int)keyPressed]=thisFunction;
	}catch(std::exception &e){

		return false;
	}
	return true;
}
TCallBack KeyMappings::callbackFromKey(unsigned int key){
	std::string eventName=keyActionMap[key];
	TCallBack thisFunction=(*actionEffectMap)[eventName];
	return thisFunction;
}

} /* namespace enDJIN */

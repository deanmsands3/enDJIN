/*
 * EventHandler.cpp
 *
 *  Created on: Jan 3, 2015
 *      Author: Dean
 */

#include "EventHandler.h"

namespace enDJIN {

EventHandler::EventHandler() {
	// TODO Auto-generated constructor stub

}

EventHandler::~EventHandler() {
	// TODO Auto-generated destructor stub
}

} /* namespace enDJIN */

const void enDJIN::EventHandler::handleEvent(const enDJIN::Event nextEvent) {
	TEventCallBackMap::const_iterator thisEvent=this->_eventCallBackMap.find(nextEvent.getType());
	if(thisEvent==_eventCallBackMap.end()){
		throw std::runtime_error(std::string("Event not found:")+std::to_string(nextEvent.getType().u32));
	}
}

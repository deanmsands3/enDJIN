/*
 * EventProcessor.cpp
 *
 *  Created on: Jan 5, 2015
 *      Author: Dean
 */

#include "EventProcessor.h"

namespace enDJIN {

EventProcessor::EventProcessor() {
	this->_eventHandler=new EventHandler();
}
bool EventProcessor::processQueue(){
	enDJIN::Event nextEvent;
	while(_messagePump.pop(nextEvent)){
		this->_eventHandler->handleEvent(nextEvent);
	}
	return true;
}


bool EventProcessor::getNextEvent(enDJIN::Event &nextEvent) {

	return _messagePump.pop(nextEvent);
}

bool EventProcessor::pushEvent(const enDJIN::Event newEvent) {
	return _messagePump.push(newEvent);
}

const enDJIN::EventHandler* EventProcessor::getEventHandler() const {
	return _eventHandler;
}

void EventProcessor::setEventHandler(
		enDJIN::EventHandler* eventHandler) {
	_eventHandler = eventHandler;
}

EventProcessor::~EventProcessor() {
}

} /* namespace enDJIN */

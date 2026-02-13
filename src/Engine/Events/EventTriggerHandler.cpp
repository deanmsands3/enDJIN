/*
 * EventTriggerHandler.cpp
 *
 *  Created on: Jan 6, 2015
 *      Author: Dean
 */

#include "EventTriggerHandler.h"

namespace enDJIN {

EventTriggerHandler::EventTriggerHandler():_handlesTriggers(true) {
	// TODO Auto-generated constructor stub

}

EventTriggerHandler::~EventTriggerHandler() {
	// TODO Auto-generated destructor stub
}

const void EventTriggerHandler::handleEvent(const enDJIN::Event nextEvent) {
	EventHandler::handleEvent(nextEvent);
	TriggerList::iterator thisEvent=this->_triggerList.find(nextEvent.getType());
	if(thisEvent==_triggerList.end()){return;}
	for(Event e:thisEvent->second){
		//Push Events to higher Event Handler
	}

}

} /* namespace enDJIN */

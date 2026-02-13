/*
 * EventTriggerHandler.h
 *
 *  Created on: Jan 6, 2015
 *      Author: Dean
 */

#ifndef SRC_ENGINE_EVENTS_EVENTTRIGGERHANDLER_H_
#define SRC_ENGINE_EVENTS_EVENTTRIGGERHANDLER_H_

#include "EventHandler.h"
#include <vector>

namespace enDJIN {
typedef std::unordered_map<EventNumber, std::vector<enDJIN::Event>> TriggerList;

class EventTriggerHandler: public EventHandler {
	TriggerList	_triggerList;
	bool _handlesTriggers;
public:
	EventTriggerHandler();
	virtual ~EventTriggerHandler();
	const virtual void handleEvent(const enDJIN::Event nextEvent);
};

} /* namespace enDJIN */

#endif /* SRC_ENGINE_EVENTS_EVENTTRIGGERHANDLER_H_ */

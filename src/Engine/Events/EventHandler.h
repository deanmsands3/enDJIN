/*
 * EventHandler.h
 *
 *  Created on: Jan 3, 2015
 *      Author: Dean
 */

#ifndef SRC_ENGINE_EVENTS_EVENTHANDLER_H_
#define SRC_ENGINE_EVENTS_EVENTHANDLER_H_
#include "Event.h"
namespace enDJIN {
typedef std::unordered_map<std::string, enDJIN::Event> TEventNameMap;
typedef std::unordered_map<EventNumber, TCallBack> TEventCallBackMap;

class GameScreen;
class EventHandler {
protected:
	TEventNameMap _eventNameMap;
	TEventCallBackMap _eventCallBackMap;
public:
	EventHandler();
	virtual ~EventHandler();
	const virtual void handleEvent(const enDJIN::Event nextEvent);
};

} /* namespace enDJIN */

#endif /* SRC_ENGINE_EVENTS_EVENTHANDLER_H_ */

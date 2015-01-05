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
class GameScreen;
class EventHandler {
public:
	EventHandler();
	virtual ~EventHandler();
};

} /* namespace enDJIN */

#endif /* SRC_ENGINE_EVENTS_EVENTHANDLER_H_ */

/*
 * Event.h
 *
 *  Created on: Jan 3, 2015
 *      Author: Dean
 */

#ifndef ENGINE_EVENT_H_
#define ENGINE_EVENT_H_
#include <SFML/Graphics.hpp>
#include "Util/Util.h"
namespace enDJIN {
typedef enum {
	UKNOWN,
	WINDOW,
	ACTOR
}EventType;
class Event {
protected:
	VersaType32 type;
	void *payload;
public:
	Event();
	Event(const Event& rhs);
	//Event operator=(const Event& rhs);
};

class WindowEvent:public Event{
public:
	WindowEvent();
};

class ActorEvent:public Event{
public:
	ActorEvent();
};
} /* namespace enDJIN */

#endif /* ENGINE_EVENT_H_ */

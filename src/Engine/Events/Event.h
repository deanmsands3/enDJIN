/*
 * Event.h
 *
 *  Created on: Jan 3, 2015
 *      Author: Dean
 */

#pragma once
#ifndef ENGINE_EVENT_H_
#define ENGINE_EVENT_H_

#include <SFML/Graphics.hpp>
#include <unordered_map>
#include "../../Util/Util.h"

namespace enDJIN {
typedef VersaType32 EventNumber;
typedef enum {
	UKNOWN=0,
	WINDOW=1,
	SCREEN=2,
	AUDIO=3,
	OBJECT=4,
	ENTITY=5,
	ACTOR=6,
	STATIC=7
}EventType;
class Event {
protected:
	void *payload;
	EventNumber type;
public:
	Event();
	Event(EventNumber eventNumber, const void *newPayload);
	Event(EventType eventType, uint16_t eventSubType, const void *newPayload);
	Event(const Event& rhs);
	[[nodiscard]] void *getPayload() const;
	[[nodiscard]] const EventNumber getType() const;

};

class WindowEvent:public Event{
public:
	WindowEvent();
};
class AudioEvent:public Event{
public:
	AudioEvent();
};
class ScreenEvent:public Event{
public:
	ScreenEvent();
};
class ObjectEvent:public Event{
public:
	ObjectEvent();
};
class EntityEvent:public Event{
public:
	EntityEvent();
};
class ActorEvent:public Event{
public:
	ActorEvent();
};
class StaticEvent:public Event{
public:
	StaticEvent();
};

} /* namespace enDJIN */
template <>
struct std::hash<enDJIN::Event>{
	size_t operator()(const enDJIN::Event &x ) const noexcept {
		uint64_t eventHash=0LL;
		int iter=0;
		constexpr int iterSteps = sizeof(enDJIN::EventNumber) + sizeof(void *);
		const auto *ptr = reinterpret_cast<uint8_t *>(&eventHash);
		for(iter=0;iter<iterSteps;iter++){
			eventHash*=31ULL;
			eventHash+=static_cast<uint64_t>(ptr[iter]);
		}
		return hash<uint64_t>()(eventHash);
	}
};

#endif /* ENGINE_EVENT_H_ */

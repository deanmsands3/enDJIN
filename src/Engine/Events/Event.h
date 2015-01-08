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
#include <unordered_map>
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
	Event(const EventNumber eventNumber, const void *newPayload);
	Event(const EventType eventType, const uint16_t eventSubType, const void *newPayload);
	Event(const Event& rhs);
	void *getPayload() const;
	const EventNumber getType() const;

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
namespace std {
    template <>
        class hash<enDJIN::Event>{
        public :
        size_t operator()(const enDJIN::Event &x ) const{
        	register uint64_t eventHash=0LL;
        	register int iterSteps;
        	register int iter=0;
        	iterSteps=sizeof(enDJIN::EventNumber) + sizeof(void*);
        	for(iter=0;iter<iterSteps;iter++){
        		eventHash*=31ULL;
        		eventHash+=(uint64_t)(((uint8_t*)(&x))[iter]);
        	}
            return hash<uint64_t>()(eventHash);
        }
    };
}

#endif /* ENGINE_EVENT_H_ */

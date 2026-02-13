/*
 * Event.cpp
 *
 *  Created on: Jan 3, 2015
 *      Author: Dean
 */

#include "Event.h"

namespace enDJIN {

Event::Event():payload(nullptr) {
	this->type.u32=0;
}

Event::Event(const Event& rhs){
	this->type.u32=rhs.type.u32;
	this->payload=rhs.payload;
}


WindowEvent::WindowEvent() {
}

ActorEvent::ActorEvent() {
}

void* Event::getPayload() const{
	return (void *)this->payload;
}

Event::Event(const EventNumber eventType, const void* newPayload) {
	this->type.u32=eventType.u32;
	this->payload=const_cast<void*>(newPayload);
}

const VersaType32 Event::getType() const{
	return (const VersaType32)this->type;
}


} /* namespace enDJIN */


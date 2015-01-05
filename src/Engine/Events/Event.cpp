/*
 * Event.cpp
 *
 *  Created on: Jan 3, 2015
 *      Author: Dean
 */

#include "Event.h"

namespace enDJIN {

Event::Event() {

}

Event::Event(const Event& rhs){
	this->type.u32=rhs.type.u32;
	this->payload=rhs.payload;
}


WindowEvent::WindowEvent() {
}

ActorEvent::ActorEvent() {
}

} /* namespace enDJIN */


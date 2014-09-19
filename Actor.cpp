/*
 * Actor.cpp
 *
 *  Created on: Sep 15, 2014
 *      Author: Dean
 */

#include "Actor.h"

namespace enDJIN {

Actor::Actor() {
	// TODO Auto-generated constructor stub

}

Actor::~Actor() {
	// TODO Auto-generated destructor stub
}
Vect2D Actor::getVelocity() const {
	return velocity;
}

void Actor::setVelocity(Vect2D velocity) {
	this->velocity = velocity;
}
void Actor::update(){
	Vect2D t=this->getLocation();
	t.x+=this->velocity.x;
	t.y+=this->velocity.y;
	setLocation(t);
}
} /* namespace enDJIN */

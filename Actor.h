/*
 * Actor.h
 *
 *  Created on: Sep 15, 2014
 *      Author: Dean
 */

#ifndef ACTOR_H_
#define ACTOR_H_

#include "Entity.h"

namespace enDJIN {

class Actor: public Entity {
private:
	Vect2D velocity;
public:
	void update();
	Actor();
	virtual ~Actor();

	Vect2D getVelocity() const;
	void setVelocity(Vect2D velocity);
};

} /* namespace enDJIN */

#endif /* ACTOR_H_ */

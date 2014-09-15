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
public:
	Actor();
	virtual ~Actor();
};

} /* namespace enDJIN */

#endif /* ACTOR_H_ */

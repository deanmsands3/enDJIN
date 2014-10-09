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
	sf::Vector2f velocity;
public:
	void update();
	Actor(std::string filename);
	virtual ~Actor();

	sf::Vector2f getVelocity() const;
	void setVelocity(sf::Vector2f velocity);
};

} /* namespace enDJIN */

#endif /* ACTOR_H_ */

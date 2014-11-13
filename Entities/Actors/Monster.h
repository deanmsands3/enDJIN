/*
 * Monster.h
 *
 *  Created on: Sep 15, 2014
 *      Author: Dean
 */

#ifndef MONSTER_H_
#define MONSTER_H_

#include "Actor.h"

namespace enDJIN {
//Known States:
//Idle
//Wandering
//Chasing Player
//Long Range Attack
//Melee Attack
//"Ouch"
//Dying
class Monster: public Actor {
public:
	Monster(std::string filename);
	virtual ~Monster();
};

} /* namespace enDJIN */

#endif /* MONSTER_H_ */

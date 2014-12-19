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
	MonsterStates state;
public:
	Monster(std::string filename);
	virtual ~Monster();
	virtual ActorStates updateIdle();
	virtual ActorStates updateWandering();
	virtual ActorStates updateHunting();
	virtual ActorStates updateRunning();
	virtual ActorStates updateJumping();
	virtual ActorStates updateFalling();
	virtual ActorStates updateAttacking();
	virtual ActorStates updateAttackingFar();
	virtual ActorStates updateStunned();
	virtual ActorStates updateDying();
};

} /* namespace enDJIN */

#endif /* MONSTER_H_ */

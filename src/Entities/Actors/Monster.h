/*
 * Monster.h
 *
 *  Created on: Sep 15, 2014
 *      Author: Dean
 */

#ifndef ENDJIN_MONSTER_H_
#define ENDJIN_MONSTER_H_

#include "Actor.h"
#include "ArmorsAttacks/Armors.h"

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
	//unsigned long health; //Inherited from Actor
	Armor armor;
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
	const Armor& getArmor() const;
	void setArmor(const Armor& armor);
	virtual void receiveAttack(const Attack &attack);
};

}; /* namespace enDJIN */

#endif /* ENDJIN_MONSTER_H_ */

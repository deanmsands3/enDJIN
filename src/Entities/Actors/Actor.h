/*
 * Actor.h
 *
 *  Created on: Sep 15, 2014
 *      Author: Dean
 */

#ifndef ACTOR_H_
#define ACTOR_H_
#include "Entities/Entity.h"
#include "ArmorsAttacks/Armors.h"
namespace enDJIN {

typedef enum {
	IDLE,
	WANDERING,
	HUNTING,
	RUNNING,
	JUMPING,
	FALLING,
	ATTACKING,
	ATTACKINGFAR,
	STUNNED,
	DYING,
	DEAD
}ActorStates;
class Attack;
class Armor;
class Actor: public Entity {
private:
	sf::Vector2f velocity;
	ActorStates state;
	unsigned int innerState;
	unsigned long health;
	unsigned long baseHealth;
	Armor armor;
public:
	void update();
	Actor(std::string filename);
	virtual ~Actor();
	sf::Vector2f getVelocity() const;
	void setVelocity(sf::Vector2f velocity);
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
	virtual void receiveAttack(const Attack &attack);
	void setInnerState(const unsigned int newInnerState);
	unsigned int getInnerState() const;
	void reduceHealth(const unsigned long damage);
	void increaseHealth(const unsigned long healing);
	void setBaseHealth(const unsigned long newBaseHealth);
	bool isWearingArmor();
};

} /* namespace enDJIN */

#endif /* ACTOR_H_ */

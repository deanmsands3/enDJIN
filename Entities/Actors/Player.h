/*
 * Player.h
 *
 *  Created on: Sep 15, 2014
 *      Author: Dean
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "Actor.h"

namespace enDJIN {
typedef enum {
	IDLE,
	RUNNING,
	JUMPING,
	FALLING,
	ATTACKING,
	ATTACKINGFAR,
	STUNNED,
	DYING,
	DEAD
}PlayerStates;
class Player: public Actor {
public:
	Player(std::string filename);
	virtual ~Player();
};

} /* namespace enDJIN */

#endif /* PLAYER_H_ */

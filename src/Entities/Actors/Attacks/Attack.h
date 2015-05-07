/*
 * Attack.h
 *
 *  Created on: Mar 16, 2015
 *      Author: Android1
 */

#ifndef SRC_ENTITIES_ATTACKS_ATTACK_H_
#define SRC_ENTITIES_ATTACKS_ATTACK_H_
#include "../Actors.h"
namespace enDJIN {
class Attack {
	unsigned long _intensity;
	unsigned long _type;
public:
	Attack(unsigned long newIntensity, unsigned long newType);
	virtual ~Attack();
	void damage(Actor * target);
	unsigned long getIntensity() const;
	void setIntensity(unsigned long intensity);
	unsigned long getType() const;
	void setType(unsigned long type);
};
};
#endif /* SRC_ENTITIES_ATTACKS_ATTACK_H_ */

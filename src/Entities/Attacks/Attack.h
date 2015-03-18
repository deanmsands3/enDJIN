/*
 * Attack.h
 *
 *  Created on: Mar 16, 2015
 *      Author: Android1
 */

#ifndef SRC_ENTITIES_ATTACKS_ATTACK_H_
#define SRC_ENTITIES_ATTACKS_ATTACK_H_

class Attack {
	unsigned long intensity;
	unsigned long type;
public:
	Attack();
	virtual ~Attack();
	unsigned long getIntensity() const;
	void setIntensity(unsigned long intensity);
	unsigned long getType() const;
	void setType(unsigned long type);
};

#endif /* SRC_ENTITIES_ATTACKS_ATTACK_H_ */

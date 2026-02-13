/*
 * Attack.h
 *
 *  Created on: Mar 16, 2015
 *      Author: Android1
 */

#ifndef SRC_ENTITIES_ATTACKS_ATTACK_H_
#define SRC_ENTITIES_ATTACKS_ATTACK_H_
#include "../Actor.h"
namespace enDJIN {
class Actor;
class Armor;
class Attack {
	unsigned long _intensity;
	unsigned long _type;
	static std::unordered_map<unsigned long,std::string> _attackRegistry;
public:
	Attack(unsigned long newIntensity, unsigned long newType);
	static void registerAttackType(const unsigned long newAttackType, const std::string &newAttackName);
	virtual ~Attack();
	void damage(Actor * target);
	unsigned long getIntensity() const;
	void setIntensity(unsigned long intensity);
	unsigned long getType() const;
	void setType(unsigned long type);
	std::string getTypeName() const;
};
};
#endif /* SRC_ENTITIES_ATTACKS_ATTACK_H_ */

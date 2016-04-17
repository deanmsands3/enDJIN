/*
 * Armor.h
 *
 *  Created on: Mar 16, 2015
 *      Author: Android1
 */

#ifndef SRC_ENTITIES_ACTORS_ARMORSATTACKS_ARMOR_H_
#define SRC_ENTITIES_ACTORS_ARMORSATTACKS_ARMOR_H_
#include <json/json.h>
#include <unordered_map>
#include <string>
#include "../Actor.h"
namespace enDJIN{
class Attack;
class Armor {
private:
	std::string _name;
	static std::unordered_map<std::string,Armor> _armorRegistry;
	void registerThisArmor();
	std::unordered_map<std::string,double> _attackResistance;
	void registerAttackResistance(std::string attackName,double resistance);
public:
	Armor(const Json::Value &jV);
	virtual ~Armor();
	static void registerArmor(const std::string name, const Armor& newArmor);
	double getAttackDamage(const Attack *attack);
	double getAttackDamage(const std::string attack);
	Armor();
	Armor(const Armor& that);
};
};
#endif /* SRC_ENTITIES_ACTORS_ARMORSATTACKS_ARMOR_H_ */

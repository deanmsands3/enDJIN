/*
 * Armor.cpp
 *
 *  Created on: Mar 16, 2015
 *      Author: Android1
 */

#include "Armor.h"
namespace enDJIN{
Armor::Armor() {
}


Armor::~Armor() {
	// TODO Auto-generated destructor stub
}

void Armor::registerThisArmor() {
	_armorRegistry[_name]=(const Armor&)(*this);
}

Armor::Armor(const Json::Value &jV) {
	_name=jV["name"].asString();
	for(auto _attack:jV["attacks"]){
		registerAttackResistance(_attack["name"].asString(),_attack["resistance"].asDouble());
	}
	registerThisArmor();
}
void Armor::registerAttackResistance(std::string attackName,double resistance){
	_attackResistance[attackName]=resistance;
}


void Armor::registerArmor(const std::string name, const Armor& newArmor){
	_armorRegistry[name]=newArmor;
}

double Armor::getAttackDamage(const Attack *attack){
	return getAttackDamage(attack->getType())
}
double Armor::getAttackDamage(const std::string attack){

}



Armor::Armor(const Armor& that) {
	_name=that._name;
	for(auto thisAttack:that._attackResistance){
		_attackResistance[thisAttack.first]=thisAttack.second;
	}
}
std::unordered_map<std::string,Armor> Armor::_armorRegistry;

}
;

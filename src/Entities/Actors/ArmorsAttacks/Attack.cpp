/*
 * Attack.cpp
 *
 *  Created on: Mar 16, 2015
 *      Author: Android1
 */

#include "Attack.h"
namespace enDJIN {
Attack::Attack(unsigned long newIntensity, unsigned long newType):_intensity(newIntensity),_type(newType) {}

unsigned long Attack::getIntensity() const {return _intensity;}

void Attack::setIntensity(unsigned long intensity) {_intensity = intensity;}

unsigned long Attack::getType() const {return _type;}

void Attack::setType(unsigned long type) {_type = type;}

Attack::~Attack() {}

void Attack::registerAttackType(const unsigned long newAttackType,const std::string &newAttackName) {
	_attackRegistry.insert(std::make_pair<unsigned long,std::string>(newAttackName,newAttackType));
}

void Attack::damage(Actor* target) {
}

std::string Attack::getTypeName() const {
	return _attackRegistry.at(this)
}
std::unordered_map<unsigned long,std::string> Attack::_attackRegistry;
}
;


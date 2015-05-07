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

};


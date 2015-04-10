/*
 * Attack.cpp
 *
 *  Created on: Mar 16, 2015
 *      Author: Android1
 */

#include "Attack.h"
namespace enDJIN {
Attack::Attack() {
	// TODO Auto-generated constructor stub

}

unsigned long Attack::getIntensity() const {
	return intensity;
}

void Attack::setIntensity(unsigned long intensity) {
	this->intensity = intensity;
}

unsigned long Attack::getType() const {
	return type;
}

void Attack::setType(unsigned long type) {
	this->type = type;
}

Attack::~Attack() {
	// TODO Auto-generated destructor stub
}
};


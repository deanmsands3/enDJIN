/*
 * Entity.h
 *
 *  Created on: Sep 15, 2014
 *      Author: Dean
 */

#ifndef ENTITY_H_
#define ENTITY_H_

namespace enDJIN {
typedef struct Vect2D{
	float x;
	float y;
};
typedef struct Vect3D{
	float x;
	float y;
	float z;
};
class Entity {
private:
	Vect2D location;
public:
	Entity();
	virtual ~Entity();
	virtual void update();
	Vect2D getLocation() const {
		return location;
	}

	void setLocation(Vect2D location) {
		this->location = location;
	}
};

} /* namespace enDJIN */

#endif /* ENTITY_H_ */

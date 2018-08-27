#ifndef BULLET_H
#define BULLET_H

#include "Entity.hpp"

class Bullet: public Entity {

public:
	Bullet(float temp);


private:
	void move();

};

#endif
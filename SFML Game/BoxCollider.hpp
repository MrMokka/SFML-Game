#ifndef BOX_COLLIDER_H
#define BOX_COLLIDER_H

#include "Collider.hpp"

class BoxCollider : public Collider{

public:
	BoxCollider();

	bool isColliding(Collider c);

private:
	float x, y, width, height;



};

#endif
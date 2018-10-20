#include "Collider.hpp"



Collider::Collider(){

}

bool Collider::isColliding(Collider other){
	/*
	BoxCollider* bc = dynamic_cast<BoxCollider*>(&other);
	//BoxCollider* me = dynamic_cast<BoxCollider*>(this);
	bool isBox = *bCol->isBoxCollider(other);

	if(me != nullptr && bc != nullptr){
		//return AABBColliding(*me, *bc);
	}
	

	*/
	return false;
}

void Collider::setCenter(sf::Vector2f center){
	this->center = center;
}




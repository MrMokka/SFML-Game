#include "Collider.hpp"


Collider::Collider(){

}

bool Collider::colliding(Collider col1, Collider col2){
	
	//BoxCollider* bc = dynamic_cast<BoxCollider*>(&col1);



	
	return false;
}

void Collider::setCenter(sf::Vector2f center){
	this->center = center;
}


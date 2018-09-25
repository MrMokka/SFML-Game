#include "Collider.hpp"


Collider::Collider(){

}

bool Collider::isColliding(Collider other){
	return false;
}

void Collider::setCenter(sf::Vector2f center){
	this->center = center;
}

bool Collider::AABBColliding(Collider colA, Collider colB){
	return false;
}


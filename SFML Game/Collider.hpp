#ifndef COLLIDER_H
#define COLLIDER_H

#include <iostream>
#include <SFML/Graphics.hpp>


class Collider {
public:
	Collider();

	virtual bool isColliding(Collider other);
	void setCenter(sf::Vector2f center);


protected:
	
	//bool AABBColliding(BoxCollider colA, BoxCollider colB);

	std::vector<Collider> colidingWith;
	sf::Vector2f center;

};


#endif

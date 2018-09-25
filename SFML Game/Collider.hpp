#ifndef COLLIDER_H
#define COLLIDER_H

#include <iostream>
#include <SFML/Graphics.hpp>


class Collider {
public:
	Collider();

	virtual bool isColliding(Collider other);
	void setCenter(sf::Vector2f center);

private:

	std::vector<Collider> colidingWith;

protected:
	
	bool AABBColliding(Collider colA, Collider colB);


	sf::Vector2f center;

};


#endif

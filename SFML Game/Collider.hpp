#ifndef COLLIDER_H
#define COLLIDER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "BoxCollider.hpp"


class Collider {
public:
	Collider();

	bool colliding(Collider col1, Collider col2);
	void setCenter(sf::Vector2f center);

private:

	std::vector<Collider> colidingWith;

protected:

	sf::Vector2f center;

};


#endif

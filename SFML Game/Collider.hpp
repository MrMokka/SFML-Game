#ifndef COLLIDER_H
#define COLLIDER_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Collider {

public:
	Collider();

	virtual bool isColliding(Collider c);
	virtual void updateCollider(sf::Vector2f center);
	virtual void drawCollider(sf::RenderWindow& windowRef);

	///////
	/// Coordinates of the bounding box for a boxCollider
	/// x1, y1 is top left corner
	/// x2, y2 is bottom right corner of bounding box
	//////
	struct coordinates{
		sf::Vector2f center;
		float x1 = 0;
		float y1 = 0;
		float x2 = 0;
		float y2 = 0;
	};

private:


protected:
	coordinates co;

};


#endif

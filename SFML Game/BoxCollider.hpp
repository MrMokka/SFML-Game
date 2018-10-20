#ifndef BOX_COLLIDER_H
#define BOX_COLLIDER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Collider.hpp"

class BoxCollider: public Collider {

public:
	
	struct Offset{
		float yTop, yBottom, xLeft, xRight;
	};

	struct Sides{
		float top, right, bottom, left;
	};

	struct Corners{
		//Top Left, Top Right, Bottom Left, Bottom Right
		sf::Vector2f topLeft, topRight, botLeft, botRight;
	};

	BoxCollider();
	BoxCollider(Offset off, sf::Vector2f center);

	bool isColliding(Collider* other);
	void updateCollider(sf::Vector2f center);
	void drawCollider(sf::RenderWindow& windowRef);

	bool isRotated(){ return rotated; }
	Corners getCorners(){ return corners; }
	Sides getSides(){ return sides; }


private:

	bool AABBColliding(BoxCollider other);

	bool rotateable;
	bool rotated;
	
	sf::RectangleShape r;
	sf::ConvexShape colBox;

	//Corners of the collision box
	Corners corners;
	//Offset from the middle (to each edge is compined by 2 offsets)
	Offset offset;
	//Single side of the box, top side is only y coord
	Sides sides;
	//Center of the collision box
	sf::Vector2f center;

};

#endif
#ifndef BOX_COLLIDER_H
#define BOX_COLLIDER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Collider.hpp"

class BoxCollider: public Collider {

public:

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

	BoxCollider();
	BoxCollider(coordinates co);

	bool isColliding(Collider other);
	void updateCollider(sf::Vector2f center, float rotation);
	void drawCollider(sf::RenderWindow& windowRef);

	bool isRotated(){ return rotated; }

	coordinates getCordinates();

	struct Corners{
		float xp[4];
		float yp[4];
	};

	void setCorners(Corners corners);

private:

	bool rotateable;
	float xp[4];
	float yp[4];
	bool rotated;

	coordinates co;
	
	sf::RectangleShape r;
	sf::ConvexShape colBox;
	float x, y , xs, ys;


};

#endif
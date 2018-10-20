#include "BoxCollider.hpp"

BoxCollider::BoxCollider(){}

BoxCollider::BoxCollider(Offset off, sf::Vector2f center){
	
	this->offset = off;
	this->center = center;

	corners.topLeft = sf::Vector2f(center.x + offset.xLeft, center.y + offset.yTop);
	corners.topRight = sf::Vector2f(center.x + offset.xRight, center.y + offset.yTop);
	corners.botLeft = sf::Vector2f(center.x + offset.xLeft, center.y + offset.yBottom);
	corners.botRight = sf::Vector2f(center.x + offset.xRight, center.y + offset.yBottom);

	sides.top = center.y + offset.yTop;
	sides.right = center.x + offset.xRight;
	sides.bottom = center.y + offset.yBottom;
	sides.left = center.x + offset.xLeft;

	colBox.setPointCount(4);
	colBox.setOutlineColor(sf::Color::Red);
	colBox.setOutlineThickness(1);
	colBox.setFillColor(sf::Color::Transparent);

	std::cout << "Box Collider created" << std::endl;

}


bool BoxCollider::isColliding(Collider* other){

	BoxCollider* bc = dynamic_cast<BoxCollider*>(other);

	if(bc != nullptr){
		if(bc->isRotated()){

		}
		return AABBColliding(*bc);
	} else{
		std::cout << "Null ptr" << std::endl;
	}
	return false;
}

//TODO: Fix bug: No detection when bigger collider hit smaller collider,
// when smaller is between all sides of bigger (only x or y not both detecting)


bool BoxCollider::AABBColliding(BoxCollider other){

	BoxCollider::Sides aSides = getSides();
	BoxCollider::Sides bSides = other.getSides();

	bool colX = false, colY = false;

	if((aSides.left >= bSides.left && aSides.left <= bSides.right)
		|| (aSides.right >= bSides.left && aSides.right <= bSides.right)){

		std::cout << "X is colliding" << std::endl;
		colX = true;
	}

	if((aSides.top >= bSides.top && aSides.top <= bSides.bottom)
		|| (aSides.bottom >= bSides.top && aSides.bottom <= bSides.bottom)){

		std::cout << "Y is colliding" << std::endl;
		colY = true;
	}

	return colX && colY;
}


void BoxCollider::updateCollider(sf::Vector2f center){

	this->center = center;

	corners.topLeft = sf::Vector2f(center.x + offset.xLeft, center.y + offset.yTop);
	corners.topRight = sf::Vector2f(center.x + offset.xRight, center.y + offset.yTop);
	corners.botLeft = sf::Vector2f(center.x + offset.xLeft, center.y + offset.yBottom);
	corners.botRight = sf::Vector2f(center.x + offset.xRight, center.y + offset.yBottom);

	sides.top = center.y + offset.yTop;
	sides.right = center.x + offset.xRight;
	sides.bottom = center.y + offset.yBottom;
	sides.left = center.x + offset.xLeft;

}


void BoxCollider::drawCollider(sf::RenderWindow & windowRef){
	
	colBox.setPoint(0, corners.topLeft);
	colBox.setPoint(1, corners.topRight);
	colBox.setPoint(2, corners.botRight);
	colBox.setPoint(3, corners.botLeft);
	
	//r.setPosition(co.center.x, co.center.y);
	//r.setPosition(co.x - (co.sx / 2), co.y - (co.sy / 2));

	//windowRef.draw(r);
	windowRef.draw(colBox);

	//std::cout << "x: " << r.getPosition().x << std::endl;

}


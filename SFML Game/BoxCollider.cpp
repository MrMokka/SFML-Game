#include "BoxCollider.hpp"

BoxCollider::BoxCollider(){}

BoxCollider::BoxCollider(BoxCollider::coordinates co){
	
	this->co = co;

	x = co.center.x + co.x1;
	xs = co.center.x + co.x2;
	y = co.center.y + co.y1;
	ys = co.center.y + co.y2;

	float sizeX = co.x2 - co.x1;
	float sizeY = co.y2 - co.y1;
	r.setSize(sf::Vector2f(sizeX, sizeY));
	r.setOutlineColor(sf::Color::Red);
	r.setOutlineThickness(1);
	//r.setRotation();
	r.setFillColor(sf::Color::Transparent);
	r.setOrigin(sf::Vector2f(sizeX / 2, sizeY / 2));

	colBox.setPointCount(4);
	colBox.setOutlineColor(sf::Color::Red);
	colBox.setOutlineThickness(1);
	colBox.setFillColor(sf::Color::Transparent);

	std::cout << "Box Collider created" << std::endl;

}


bool BoxCollider::isColliding(Collider other){

	BoxCollider* bc = dynamic_cast<BoxCollider*>(&other);

	if(bc != nullptr){
		if(bc->isRotated()){

		}
		return AABBColliding(*this, *bc);
	}


	/*
	coordinates oCol = c.getCordinates();

	float x1 = oCol.center.x + oCol.x1;
	float x2 = oCol.center.x + oCol.x2;
	float y1 = oCol.center.y + oCol.y1;
	float y2 = oCol.center.y + oCol.y2;

	//std::cout << "x1: " << x1 << " x2: " << x2 << " y1: " << y1 << " y2: " << y2 << std::endl;
	//std::cout << "x: " << x << " xs: " << xs << " y: " << y << " ys: " << ys << std::endl;

	if((x >= x1 && x <= x2) || (xs >= x1 && xs <= x2)) {
		
		//std::cout << "X is colliding" << std::endl;

		if((y >= y1 && y <= y2) || (ys >= y1 && ys <= y2)){

			//std::cout << this << " is colliding with " << &c << std::endl;
			return true;
		}

	}
	*/
	return false;
}

void BoxCollider::updateCollider(sf::Vector2f center, float rotation){
	
	co.center = center;

	x = co.center.x + co.x1;
	xs = co.center.x + co.x2;
	y = co.center.y + co.y1;
	ys = co.center.y + co.y2;

	r.setRotation(rotation);

}


void BoxCollider::drawCollider(sf::RenderWindow & windowRef){
	
	colBox.setPoint(0, sf::Vector2f(x, y));
	colBox.setPoint(1, sf::Vector2f(xs, y));
	colBox.setPoint(2, sf::Vector2f(xs, ys));
	colBox.setPoint(3, sf::Vector2f(x, ys));
	
	//r.setPosition(co.center.x, co.center.y);
	//r.setPosition(co.x - (co.sx / 2), co.y - (co.sy / 2));

	//windowRef.draw(r);
	windowRef.draw(colBox);

	//std::cout << "x: " << r.getPosition().x << std::endl;

}


BoxCollider::coordinates BoxCollider::getCordinates(){
	return this->co;
}



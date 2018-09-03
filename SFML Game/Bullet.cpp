#include "Bullet.hpp"



Bullet::Bullet(GameObject::createOptions options){
	this->size = options.size;
	this->xPos = options.xPos;
	this->yPos = options.yPos;
	tx = options.texture;
	tx->setSmooth(true);

	body.setTexture(tx);
	//body.setFillColor(sf::Color::Red);
	body.setSize(sf::Vector2f(size / 1.5, size));
	body.setOrigin(sf::Vector2f(body.getSize().x / 2, body.getSize().y / 2));
	body.setPosition(xPos, yPos);


	std::cout << "Bullet Created" << std::endl;
}



void Bullet::update(float deltaTime){
	move(deltaTime);
}



void Bullet::draw(sf::RenderWindow& windowRef){

	windowRef.draw(body);
	//windowRef.draw(sprite);

}

void Bullet::setDir(sf::Vector2f direction){
	moveDir = direction;
}

void Bullet::setRotation(float rotDeg){
	body.setRotation(rotDeg);
	
	moveDir.y = -(cos(body.getRotation() * M_PI / 180));
	moveDir.x = (sin(body.getRotation() * M_PI / 180));
	
	//std::cout << "X: " << moveDir.x << " Y: " << moveDir.y << std::endl;
}


void Bullet::move(float deltaTime){


	float moveX = moveDir.x * moveSpeed * deltaTime;
	float moveY = moveDir.y * moveSpeed * deltaTime;

	xPos += moveX;
	yPos += moveY;

	body.setPosition(xPos, yPos);

	//std::cout << "X: " << xPos << " Y: " << yPos << std::endl;



}




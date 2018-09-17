#include "Coin.hpp"

#include <stdlib.h>
#include <iostream>


Coin::Coin(GameObject::createOptions options){
	this->size = options.size;
	this->xPos = options.xPos;
	this->yPos = options.yPos;

	tx = options.texture;

	body.setTexture(tx);
	//body.setFillColor(sf::Color::White);
	body.setSize(sf::Vector2f(size, size));
	body.setOrigin(sf::Vector2f(size / 2, size / 2));
	body.setPosition(xPos, yPos);

	BoxCollider::coordinates c;
	c.center = sf::Vector2f(xPos, yPos);
	c.x1 = -(size / 2);
	c.y1 = -(size / 2);
	c.x2 = (size / 2);
	c.y2 = (size / 2);

	bc = BoxCollider(c);

	std::cout << "Coin Made" << std::endl;

}


void Coin::update(float deltaTime){
	
	

	rotationTimer += deltaTime;
	if(rotationTimer > rotationSpeed){
		rotationTimer = 0;
		textureNum++;
		if(textureNum == 4){
			textureNum = 0;
		}
	}

	
	body.setTextureRect(sf::IntRect(textureNum * 64, 0, 64, 64));
	body.setPosition(xPos, yPos);

	bc.updateCollider(sf::Vector2f(xPos, yPos), body.getRotation());

}

void Coin::draw(sf::RenderWindow & windowRef){

	//body.setPosition(xPos - size, yPos - size);
	windowRef.draw(body);

	if(Settings::drawColliders()){
		bc.drawCollider(windowRef);
	}

}

void Coin::UpdateCollision(){

}

float Coin::getXPos(){
	return xPos;
}

float Coin::getYPos(){
	return yPos;
}

float Coin::getSize(){
	return size;
}

void Coin::respawn(){
	xPos = rand() % (Settings::getWindowWidth() - 20) + 20;
	yPos = rand() % (Settings::getWindowHeigth() - 20) + 20;
}





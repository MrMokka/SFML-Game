#include "Coin.hpp"

#include <stdlib.h>
#include <iostream>


Coin::Coin(float size){
	this->size = size;
	color = sf::Color::Red;

	body.setRadius(this->size);
	body.setFillColor(sf::Color::Yellow);

	xPos = 200;
	yPos = 200;

	body.setPosition(xPos - size, yPos - size);

	//std::cout << "Coin Made" << std::endl;

}


void Coin::Update(float deltaTime){
	
}

void Coin::draw(sf::RenderWindow & windowRef){

	body.setPosition(xPos - size, yPos - size);
	windowRef.draw(body);

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





#include "Coin.hpp"

#include <stdlib.h>
#include <iostream>


Coin::Coin(GameObject::createOptions options){
	this->size = options.size;
	this->xPos = options.xPos;
	this->yPos = options.yPos;

	tx = *options.texture;

	

	sprites[0].setTextureRect(sf::IntRect(0, 0, 64, 64));
	sprites[1].setTextureRect(sf::IntRect(64, 64, 128, 128));
	sprites[2].setTextureRect(sf::IntRect(128, 128, 192, 192));
	sprites[3].setTextureRect(sf::IntRect(192, 192, 256, 256));

	//color = sf::Color::Red;

	//body.setRadius(this->size);
	//body.setFillColor(sf::Color::Yellow);

	//body.setPosition(xPos - size, yPos - size);

	//std::cout << "Coin Made" << std::endl;

}


void Coin::Update(float deltaTime){
	
	sprites[spriteNum].setPosition(xPos, yPos);


}

void Coin::draw(sf::RenderWindow & windowRef){

	//body.setPosition(xPos - size, yPos - size);
	windowRef.draw(sprites[spriteNum]);

}

void Coin::UpdateCollision(){

}

void Coin::createSprites(){
	/*
	 = new sf::RectangleShape();



	sprite.setTexture(tx);
	sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2));
	sprite.setPosition(0, 0);
	*/

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





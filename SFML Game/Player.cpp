#include "Player.hpp"
#include <SFML/Graphics.hpp>
#include "Coin.hpp"
#include <cmath>
#include <iostream>

#define _USE_MATH_DEFINES
#include <math.h>

Player::Player(GameObject::createOptions options){
	this->size = options.size;
	this->xPos = options.xPos;
	this->yPos = options.yPos;
	
	tx = options.texture;

	tx->setSmooth(true);

	body.setTexture(tx);
	//body.setFillColor(sf::Color::Red);
	body.setSize(sf::Vector2f(size, size));
	body.setOrigin(sf::Vector2f(size / 2, size / 2));
	body.setPosition(xPos, yPos);

	//body.setRadius(this->size);

	/*
	sprite.setTexture(tx);
	sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	sprite.setOrigin(sf::Vector2f(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2));
	sprite.setPosition(0, 0);
	*/
	

	moveSpeed = 150;
	moveBonus = 2.0;

	std::cout << "Player Created" << std::endl;

}


void Player::update(float deltaTime){
	MovePlayer(deltaTime);
}


void Player::MovePlayer(float deltaTime){

	//std::cout << "Player Update" << std::endl;

	sf::Vector2f dir;
	float moveBoost = 1.0f;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)) dir.x += 1;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)) dir.x -= 1;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) dir.y -= 1;
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) dir.y += 1;

	if(sf::Keyboard::isKeyPressed(sf::Keyboard::LShift)) moveBoost = moveBonus;

	
	sf::Vector2i mousePos = sf::Mouse::getPosition(*Settings::getRenderWindow());

	sf::Vector2f targetVec = sf::Vector2f((float) mousePos.x, (float) mousePos.y);
	sf::Vector2f playerVec = sf::Vector2f(xPos, yPos);

	sf::Vector2f facingVec = playerVec - targetVec;
	
	float rotation =  atan2(facingVec.x, facingVec.y) * (180 / M_PI);

	body.setRotation(-rotation);

	if(dir.x != 0 && dir.y != 0){
		dir.x *= 0.71f;
		dir.y *= 0.71f;
	}

	xPos += dir.x * moveSpeed * moveBoost * deltaTime;
	yPos += dir.y * moveSpeed * moveBoost * deltaTime;

	UpdateCollision();

	//std::cout << xPos << " : " << yPos << std::endl;

	//body.setPosition(xPos - size, yPos - size);
	body.setPosition(xPos, yPos);
}

void Player::draw(sf::RenderWindow& windowRef){
	
	windowRef.draw(body);
	//windowRef.draw(sprite);

}


void Player::UpdateCollision(){
	
	if((xPos - size) < 0) xPos = size;
	if((yPos - size) < 0) yPos = size;

	int width = Settings::getWindowWidth();
	int height = Settings::getWindowHeigth();

	if((xPos + size) > width) xPos = width - size;
	if((yPos + size) > height) yPos = height - size;
	
}

void Player::rotate(){

}



void Player::collide(std::vector<GameObject*> gameObjects){

	for(int i = 0; i < gameObjects.size(); i++) {
		//std::cout << entities[i] << std::endl;
		//std::cout << this << std::endl;
		if(gameObjects[i] == this){
			//std::cout << "Player found itself" << std::endl;
			continue;
		}
		Coin* c = dynamic_cast<Coin*>(gameObjects[i]);
		if(c != 0){
			//std::cout << "Found Coin!" << std::endl;
			float cX = c->getXPos();
			float cY = c->getYPos();
			float cS = c->getSize();

			float dx = cX - xPos;
			float dy = cY - yPos;
			float dis = std::sqrt((dx * dx) + (dy * dy));
			//std::cout << cX << " : " << cY << " : " << dis << std::endl;


			if(dis <= (cS + size) / 2){
				//std::cout << "Colliding with coin" << std::endl;
				c->respawn();
				Settings::addScore(1);
			}
			
		}

		//typeid(entities[i])
	}

}



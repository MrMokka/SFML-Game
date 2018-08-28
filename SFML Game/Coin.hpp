#ifndef COIN_H
#define COIN_H

#include "Entity.hpp"

class Coin: public Entity {

public:
	Coin(GameObject::createOptions options);
	void Update(float deltaTime);
	void draw(sf::RenderWindow& windowRef);

	float getXPos();
	float getYPos();
	float getSize();

	void respawn();

private:
	float size;
	sf::Color color;

	float xPos;
	float yPos;

	void UpdateCollision();
	void textureAnimSetup();

	sf::RectangleShape body;

	sf::Texture* tx;

	int spriteNum = 0;
	float rotationSpeed = 0.25f;
	sf::Sprite sprites[4];

};

#endif


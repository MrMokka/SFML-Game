#ifndef COIN_H
#define COIN_H

#include "Entity.hpp"

class Coin: public Entity {

public:
	Coin(float size);
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

	sf::CircleShape body;

};

#endif


#ifndef BULLET_H
#define BULLET_H

#include "Entity.hpp"

class Bullet: public Entity {

public:
	Bullet(GameObject::createOptions options);

	void update(float deltaTime);
	void draw(sf::RenderWindow & windowRef);

	void setDir(sf::Vector2f direction);
	void setRotation(float rotDeg);

private:
	sf::Vector2f moveDir;
	float moveSpeed = 100.0f;
	sf::RectangleShape body;
	sf::Texture* tx;
	float size;

	void move(float deltaTime);

};

#endif
#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.hpp"

class Player: public Entity {
public:
	Player(float size);
	void UpdatePlayer(float deltaTime);
	void draw(sf::RenderWindow& windowRef);
	void collide(std::vector<GameObject*> gameObjects);


private:
	float size;
	sf::Color color;

	sf::Vector2f moveDir;
	float moveSpeed;
	float moveBonus;

	float xPos;
	float yPos;

	void MovePlayer(float deltaTime);
	void UpdateCollision();
	void rotate();

	sf::CircleShape body;

	sf::Texture tx;
	sf::Sprite sprite;

};


#endif


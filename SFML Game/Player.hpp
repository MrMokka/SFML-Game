#ifndef PLAYER_H
#define PLAYER_H

//#define M_PI 3.141592653589793238463

#include "Entity.hpp"

class Player: public Entity {
public:
	Player(GameObject::createOptions options);
	void update(float deltaTime);
	void draw(sf::RenderWindow& windowRef);
	void collide(std::vector<GameObject*> gameObjects);


private:
	float size;
	sf::Color color;

	sf::Vector2f moveDir;
	float moveSpeed;
	float moveBonus;

	void MovePlayer(float deltaTime);
	void UpdateCollision();
	void rotate();

	sf::CircleShape body;
	
	sf::Texture tx;
	sf::Sprite sprite;

};


#endif


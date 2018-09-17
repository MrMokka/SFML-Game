#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.hpp"
#include "Game.hpp"
#include "Coin.hpp"
#include "Bullet.hpp"

class Player: public Entity {
public:
	Player(GameObject::createOptions options);
	void update(float deltaTime);
	void draw(sf::RenderWindow& windowRef);
	void collide(std::vector<GameObject*> gameObjects);


private:
	float size;
	sf::Color color;
	sf::Vector2f faceDir;
	sf::Vector2f moveDir;
	float moveSpeed;
	float moveBonus;

	void shoot(float deltaTime);
	float shootTimer = 0;
	float shootSpeed = 1.0f;

	void MovePlayer(float deltaTime);
	void UpdateCollision();
	void rotate();

	sf::RectangleShape body;
	
	sf::Texture* tx;
	//sf::Sprite sprite;

};


#endif


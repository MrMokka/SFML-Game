#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Settings.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>
#include "BoxCollider.hpp"
#include <string>

#define _USE_MATH_DEFINES
#include <math.h>


class GameObject{

public:
	GameObject();
	GameObject(float xPos, float yPos);
	~GameObject();

	virtual void draw(sf::RenderWindow& windowRef);
	virtual void update(float deltaTime);
	virtual void collide(std::vector<GameObject*> gameObjects);

	BoxCollider* getCollider();

	struct createOptions{
		float xPos = 0;
		float yPos = 0;
		float size = 0;
		sf::Color color = sf::Color::Magenta;
		sf::Texture* texture;
	};

private:



protected:
	float xPos;
	float yPos;

	BoxCollider bc;


};


#endif

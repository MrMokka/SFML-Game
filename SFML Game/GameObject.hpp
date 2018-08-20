#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Settings.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>


class GameObject{

public:
	GameObject();
	~GameObject();

	virtual void draw(sf::RenderWindow& windowRef);
	virtual void collide(std::vector<GameObject*> gameObjects);

private:



protected:


};


#endif

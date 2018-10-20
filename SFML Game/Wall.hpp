#ifndef WALL_H
#define WALL_H

#include "Entity.hpp"

class Wall: public Entity{

public:

	Wall(GameObject::createOptions options);
	void update(float deltaTime);
	void draw(sf::RenderWindow& windowRef);



private:


};



#endif
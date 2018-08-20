#include "GameObject.hpp"



GameObject::GameObject(){

}

GameObject::~GameObject(){

}

void GameObject::draw(sf::RenderWindow& windowRef){
	std::cout << "Entity Drawing" << std::endl;
}

void GameObject::collide(std::vector<GameObject*> gameObjects){

}

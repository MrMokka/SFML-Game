#include "GameObject.hpp"




GameObject::GameObject(){
}

GameObject::GameObject(float xPos, float yPos){
	this->xPos = xPos;
	this->yPos = yPos;
}

GameObject::~GameObject(){

}

void GameObject::draw(sf::RenderWindow& windowRef){
	std::cout << "Entity Drawing" << std::endl;
}

void GameObject::collide(std::vector<GameObject*> gameObjects){

}

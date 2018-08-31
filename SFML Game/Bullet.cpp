#include "Bullet.hpp"



Bullet::Bullet(float temp){

}



void Bullet::update(float deltaTime){
	MovePlayer(deltaTime);

	shoot(deltaTime);



}



void Player::draw(sf::RenderWindow& windowRef){

	windowRef.draw(body);
	//windowRef.draw(sprite);

}



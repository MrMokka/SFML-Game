#include "Game.hpp"
#include "Player.hpp"
#include <math.h>
#include <string.h>
#include "Settings.hpp"
#include "Coin.hpp"
#include "Bullet.hpp"

#include <iostream>


std::vector<GameObject*> Game::newGameObjects;
std::map<std::string, sf::Texture> Game::textureMap;


void Game::Run() {

	sf::RenderWindow window(sf::VideoMode(Settings::getWindowWidth(), Settings::getWindowHeigth()), "First Window", sf::Style::Titlebar | sf::Style::Close);

	Settings::setRenderWindow(&window);

	window.setFramerateLimit(60);

	sf::Font font;
	if(!font.loadFromFile("Gasalt-Regular.ttf")){
		std::cout << "Error loading Font!" << std::endl;
	}

	loadSprites();

	scoreText.setFont(font);
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(((float)Settings::getWindowWidth() / 3), 10.0f);
	scoreText.setString("Score: " + std::to_string(Settings::getScore()));

	frameCounter.setFont(font);
	frameCounter.setCharacterSize(20);
	frameCounter.setFillColor(sf::Color::White);
	frameCounter.setPosition(3, 1);
	frameCounter.setString("FPS: " + std::to_string((int)0));
	fpsUpdater = 0;



	GameObject::createOptions options = GameObject::createOptions();
	options.size = 32;
	options.xPos = 200;
	options.yPos = 300;
	options.texture = getTexture("player");

	createObject(Game::ObjectType::PLAYER, options);

	options.size = 16;
	options.xPos = 400;
	options.yPos = 100;
	options.texture = getTexture("coin");
	
	createObject(Game::ObjectType::COIN, options);


	//gameObjects.push_back(&coin);
	//gameObjects.push_back(&player);
	

	while(window.isOpen()) {

		sf::Event event;

		while(window.pollEvent(event)) {
			switch(event.type) {
			case sf::Event::Closed:
				window.close();
				break;
			}

		}
		
		
		window.clear();

		// Update the game
		UpdateFrames();
		collisionUpdate();

		objectLoop();

		scoreText.setString("Score: " + std::to_string(Settings::getScore()));

		//Draw objects
		
		drawLoop(window);
		window.draw(frameCounter);
		window.draw(scoreText);

		window.display();
	}
}

GameObject* Game::createObject(Game::ObjectType type, GameObject::createOptions options){
	GameObject* obj;

	switch(type){
	case Game::ObjectType::PLAYER:
		obj = new Player(options);
		//std::cout << "Player Created" << std::endl;
		break;
	case Game::ObjectType::COIN:
		obj = new Coin(options);
		//std::cout << "Coin Created" << std::endl;
		break;
	case Game::ObjectType::BULLET:
		obj = new Bullet(options);
		//std::cout << "Bullet Created" << std::endl;
		break;
	default:
		std::cout << "ERROR Creating object!" << std::endl;
		return nullptr;
		break;
	}

	newGameObjects.push_back(obj);

	return obj;
}


sf::Texture* Game::getTexture(std::string key){

	auto search = textureMap.find(key);
	if(search != textureMap.end()) {
		//std::cout << "Found " << search->first << " " << "texture" << '\n';
		//test = search->second;
	}
	else {
		std::cout << "Not found\n";
	}

	sf::Texture* tp = &search->second;

	return tp;
}


void Game::loadSprites(){
	sf::Texture tx;

#pragma region Player Sprite
	if(tx.loadFromFile("Sprites/Player.png")){
		std::cout << "Player texture loaded" << std::endl;
		mapResult = textureMap.insert(std::pair<std::string, sf::Texture>("player", tx));
	} else {
		std::cout << "Did not find Player texture" << std::endl;
	}
#pragma endregion

#pragma region Bullet Sprite
	if(tx.loadFromFile("Sprites/Bullet.png")){
		std::cout << "Bullet texture loaded" << std::endl;
		mapResult = textureMap.insert(std::pair<std::string, sf::Texture>("bullet", tx));
	} else {
		std::cout << "Did not find Bullet texture" << std::endl;
	}
#pragma endregion

#pragma region Coin Sprite
	if(tx.loadFromFile("Sprites/Coin.png")){
		std::cout << "Coin texture loaded" << std::endl;
		mapResult = textureMap.insert(std::pair<std::string, sf::Texture>("coin", tx));
	} else {
		std::cout << "Did not find Coin texture" << std::endl;
	}
#pragma endregion

	
}


void Game::UpdateFrames(){
	
	frameRate = 1.0f / clock.getElapsedTime().asSeconds();
	deltaTime = clock.getElapsedTime().asSeconds();

	clock.restart();

	//Update fps text on screen every x (0.5) second
	fpsUpdater += deltaTime;
	if(fpsUpdater >= 0.5f){
		frameCounter.setString("FPS: " + std::to_string((int)frameRate));
		fpsUpdater = 0;
	}


}


void Game::drawLoop(sf::RenderWindow& w){

	std::vector<GameObject*>::const_iterator i;
	for(i = gameObjects.begin(); i != gameObjects.end(); i++) {
		GameObject* e = *i;
		e->draw(w);
	}

	//std::cout << gameObjects.size() << std::endl;

	for(i = newGameObjects.begin(); i != newGameObjects.end(); i++) {
		gameObjects.push_back(*i);
	}
	newGameObjects.clear();
}


void Game::objectLoop(){

	std::vector<GameObject*>::const_iterator i;
	for(i = gameObjects.begin(); i != gameObjects.end(); i++) {
		GameObject* e = *i;
		e->update(deltaTime);
	}

}


void Game::collisionUpdate(){

	for(int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->collide(gameObjects);
	}


}





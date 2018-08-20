#include "Game.hpp"
#include "Player.hpp"
#include <math.h>
#include <string.h>
#include "Settings.hpp"
#include "Coin.hpp"

#include <iostream>




void Game::Run() {

	sf::RenderWindow window(sf::VideoMode(Settings::getWindowWidth(), Settings::getWindowHeigth()), "First Window", sf::Style::Titlebar | sf::Style::Close);

	Settings::setRenderWindow(&window);

	window.setFramerateLimit(60);


	sf::Font font;
	if(!font.loadFromFile("Gasalt-Regular.ttf")){
		std::cout << "Error loading Font!" << std::endl;
	}

	scoreText.setFont(font);
	scoreText.setCharacterSize(20);
	scoreText.setFillColor(sf::Color::White);
	scoreText.setPosition(((float) Settings::getWindowWidth() / 3), 10.0f);
	scoreText.setString("Score: " + std::to_string(Settings::getScore()));

	frameCounter.setFont(font);
	frameCounter.setCharacterSize(20);
	frameCounter.setFillColor(sf::Color::White);
	frameCounter.setPosition(3, 1);
	frameCounter.setString("FPS: " + std::to_string((int)0));
	fpsUpdater = 0;

	Player player(10);
	Coin coin(5);

	gameObjects.push_back(&coin);
	gameObjects.push_back(&player);
	

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

		scoreText.setString("Score: " + std::to_string(Settings::getScore()));

		player.UpdatePlayer(deltaTime);

		//Draw objects
		
		drawLoop(window);
		window.draw(frameCounter);
		window.draw(scoreText);
		//player.draw(window);

		window.display();
	}
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

}


void Game::collisionUpdate(){

	for(int i = 0; i < gameObjects.size(); i++) {
		gameObjects[i]->collide(gameObjects);
	}


}





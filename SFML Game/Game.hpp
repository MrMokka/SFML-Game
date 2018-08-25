#ifndef GAME_H
#define GAME_H

#include "GameObject.hpp"

class Game{
public:
	void Run();

private:
	sf::Text scoreText;

	sf::Text frameCounter;
	float frameRate;
	float fpsUpdater;

	float deltaTime;
	sf::Clock clock;

	void UpdateFrames();
	void drawLoop(sf::RenderWindow& w);
	void collisionUpdate();
	void loadSprites();

	std::vector<GameObject*> gameObjects;

	std::map<std::string, sf::Sprite> spriteMap;
	std::pair<std::map<std::string, sf::Sprite>::iterator, bool> mapResult;

};

#endif
#ifndef GAME_H
#define GAME_H

#include "GameObject.hpp"

class Game{
public:
	void Run();

	static enum ObjectType{
		PLAYER,
		COIN,
		BULLET
	};

	static GameObject* createObject(Game::ObjectType type, GameObject::createOptions options);
	static sf::Texture* getTexture(std::string key);
	

private:
	sf::Text scoreText;

	sf::Text frameCounter;
	float frameRate;
	float fpsUpdater;

	float deltaTime;
	sf::Clock clock;

	void UpdateFrames();
	void drawLoop(sf::RenderWindow& w);
	void objectLoop();
	void collisionUpdate();
	void loadSprites();

	static std::vector<GameObject*> newGameObjects;
	std::vector<GameObject*> gameObjects;

	

	static std::map<std::string, sf::Texture> textureMap;
	std::pair<std::map<std::string, sf::Texture>::iterator, bool> mapResult;

};

#endif
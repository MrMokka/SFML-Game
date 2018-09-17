#ifndef SETTINGS_H
#define SETTINGS_H

#include <SFML/Graphics.hpp>

class Settings{

public:
	Settings();

	static void setWindowWidth(int w);
	static void setWindowHeight(int h);

	static int getWindowWidth();
	static int getWindowHeigth();

	static void setDrawColliders(bool draw);
	static bool drawColliders();

	static void addScore(int x);
	static int getScore();

	static void setRenderWindow(sf::RenderWindow* rW);
	static sf::RenderWindow* getRenderWindow();

private:
	static int WINDOW_WIDTH;
	static int WINDOW_HEIGHT;

	static int score;

	static sf::RenderWindow* rWindow;

	static bool drawCols;
	
};

#endif

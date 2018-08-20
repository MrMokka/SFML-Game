#include "Settings.hpp"

int Settings::WINDOW_WIDTH;
int Settings::WINDOW_HEIGHT;
int Settings::score;
sf::RenderWindow* Settings::rWindow;

Settings::Settings(){

}

void Settings::setWindowWidth(int w){
	WINDOW_WIDTH = w;
}

void Settings::setWindowHeight(int h){
	WINDOW_HEIGHT = h;
}

int Settings::getWindowWidth(){
	return WINDOW_WIDTH;
}

int Settings::getWindowHeigth(){
	return WINDOW_HEIGHT;
}

void Settings::addScore(int x){
	score += x;
}

int Settings::getScore(){
	return score;
}

void Settings::setRenderWindow(sf::RenderWindow* rW){
	rWindow = rW;
}

sf::RenderWindow* Settings::getRenderWindow(){
	return rWindow;
}

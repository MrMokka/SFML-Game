#include "Game.hpp"
#include "Settings.hpp"


int main() {

	Settings settings;

	

	Settings::setWindowWidth(800);
	Settings::setWindowHeight(600);

	Game game;

	game.Run();

	return 0;

}

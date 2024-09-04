#include "Game.h"

int main()try
{
	
	Game myGame;
	myGame.runOnMenu();
	return EXIT_SUCCESS;
}
catch (std::exception& Exception)
{
	std::cout << Exception.what();
	return EXIT_FAILURE;
}




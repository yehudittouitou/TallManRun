#include "NewGame.h"
#include "Game.h"
NewGame::NewGame(Game& game)
	:m_game(game)
{
}
//--------------------------------------------------
NewGame::~NewGame(){}
//----------------------------------------
void NewGame::execute()
{
    m_game.startGame();
}



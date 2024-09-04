#include "Exit.h"
#include "Game.h"
Exit::Exit(Game& game)
	:m_game(game)
{
}
//----------------------------
Exit::~Exit()
{
}
//----------------------------
void Exit::execute()
{
	m_game.exit();
}

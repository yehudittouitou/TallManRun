#pragma once
#include "Button.h"
#include "Command.h"
class Game;

class NewGame:public Command
{
public:
	NewGame(Game&);
	virtual ~NewGame()override;
	virtual void execute()override;
private:
	Game& m_game;
	
};

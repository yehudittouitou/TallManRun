#pragma once
#include "Command.h"
class Game;
class Exit : public Command
{
public:
	Exit(Game&);
	virtual ~Exit()override;
	virtual void execute()override;
private:
	Game& m_game;   
};


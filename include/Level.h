#pragma once
#include "Board.h"
#include "Player.h"
#include "InformationDisplay.h"

class Level
{
public:
	Level(const int& numoflevel);
	~Level();
	void draw();
	bool run(int& record);
	void updateRecord(int& record);
	void updateAndMoveBoardAndPlayer();
private:

	Board m_board;                     // board 
	Player m_Player;                   // player
	InformationDisplay m_information;  //information board
};


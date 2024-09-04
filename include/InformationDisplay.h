#pragma once
#include "ResourceManeger.h"
using namespace sf;
const int NUM_OF_SHOW_HERAT = 3;
//---------------------------------------
class InformationDisplay
{
public:
	InformationDisplay();
	~InformationDisplay();
	void draw();
	void updateInformation(const int& numofCoin, const int& lives, const bool& isHaveBoat);
private:
	int m_numOfLives= NUM_OF_SHOW_HERAT;  // num of heart to draw
	bool m_needToDrawBoat = false;        // if the player have boat, he need to show pic of boat  
	Sprite m_heartPic;                    // heart picture
	float m_firstHeartPos = 220;          // the position of the first heart
	Sprite m_coinPic;                     // coin picture
	Sprite m_boatPic;                     // boat picture
	Text m_coinNumText;                   // text of coins amount
};


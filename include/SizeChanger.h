#pragma once
#include "RoadObject.h"
class Player;
class SizeChanger :public RoadObject
{
public:
	SizeChanger(char sign,int num,const int& numpic);
	virtual ~SizeChanger();
	void calculateNewSize(Player&);
	virtual void drawObject()override;
protected:
	int m_num;       // num of less/ add/ double/ divide
	sf::Text m_text; // text
};


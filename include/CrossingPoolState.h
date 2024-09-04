#pragma once
#include "State.h"
class CrossingPoolState:public State
{
public:
	CrossingPoolState(const int &, sf::Sprite& pool);
	~CrossingPoolState();
	virtual unique_ptr<State>handleInput(sf::Event)const override;
	virtual void execute(Player&) override;
	virtual void enter(Player&)override;
private:
	int m_picNum;           //pic type
	sf::Sprite& m_poolPic;  //picture of pool
};


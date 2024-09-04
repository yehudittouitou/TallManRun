#pragma once
#include "State.h"


class TurnRightState :public State
{
public:
	TurnRightState();
	virtual ~TurnRightState() {}
	virtual unique_ptr<State>handleInput(sf::Event)const override;
	virtual void execute(Player&)override;
	virtual void enter(Player&)override;

};


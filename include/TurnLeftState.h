#pragma once
#include "State.h"


class TurnLeftState :public State
{
public:
	TurnLeftState();
	virtual ~TurnLeftState() {}
	virtual unique_ptr<State>handleInput(sf::Event)const override;
	virtual void execute(Player&)override;
	virtual void enter(Player&)override;

};


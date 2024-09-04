#pragma once
#include "State.h"


class WalkingState :public State
{
public:
	WalkingState();
	virtual ~WalkingState() {}
	virtual unique_ptr<State>handleInput(sf::Event)const override;
	virtual void enter(Player&)override;

};


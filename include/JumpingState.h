#pragma once
#include "State.h"


class JumpingState :public State
{
public:
	JumpingState();
	virtual ~JumpingState() {}
	virtual unique_ptr<State>handleInput(sf::Event)const override;
	virtual void execute(Player&)override;
	virtual void enter(Player&)override;
private:
};


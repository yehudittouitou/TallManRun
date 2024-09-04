#pragma once
#include <memory>
#include "ResourceManeger.h"
using namespace std;
class Player;

class State
{
public:
	State();
	virtual ~State();
	virtual unique_ptr<State> handleInput(sf::Event e)const = 0;
	virtual void enter(Player&) = 0;
	virtual void execute(Player& player);

protected:
	sf::Clock m_clock;  //clock of move
	
};


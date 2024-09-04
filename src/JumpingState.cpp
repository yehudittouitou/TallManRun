#include "WalkingState.h"
#include "JumpingState.h"
#include "TurnLeftState.h"
#include "TurnRightState.h"
#include "Player.h"
//--------------------------------
JumpingState::JumpingState()
{
}
//------------------------------------------------------------   
unique_ptr<State> JumpingState::handleInput(sf::Event event)const 
{
	// can't move to another state in the middle of jumping!
	return nullptr;
}
//--------------------------------------------------------------------
void JumpingState::execute(Player& player)
{
	// the whole jumping is 2 second
	if (m_clock.getElapsedTime().asSeconds() < 2.5)
	{
		// if it's in the first half of the jumping time- move up
		if (m_clock.getElapsedTime().asSeconds() < 1.25)
			player.getPic().move({ 0,-4 });
		// if it's in the second half of the jumping time- move down
		else
			player.getPic().move({ 0,4 });
	}
	// if jumping time is over
	else
	{
		// back to walking state
		player.changeState(std::make_unique<WalkingState>());
	}
}
//--------------------------------------------------------------------
void JumpingState::enter(Player& player)
{
	
}





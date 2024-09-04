#include "WalkingState.h"
#include "JumpingState.h"
#include "TurnLeftState.h"
#include "TurnRightState.h"
#include "Player.h"
TurnLeftState::TurnLeftState()
{
}

//------------------------------------------------------------   
unique_ptr<State> TurnLeftState::handleInput(sf::Event event)const 
{
	//its o.k to change state
	switch (event.key.code)
	{
		
	case sf::Keyboard::Up:
		return std::make_unique<JumpingState>();
		break;
	case sf::Keyboard::Right:
		return std::make_unique<TurnRightState>();
		break;
	case sf::Keyboard::Left:
		return std::make_unique<TurnLeftState>();
		break;
	default:
		return nullptr;
	}
}
//-----------------------------------------------------
void TurnLeftState::execute(Player& player)
{
	// move the player left
	if (player.getPic().getPosition().x > 200)
	{
		player.getPic().move({ float(-1000 * m_clock.getElapsedTime().asSeconds()),0 });
	}
	// back to walking state
	player.changeState(std::make_unique<WalkingState>());
}
//--------------------------------------------------------------------
void TurnLeftState::enter(Player& player)
{
	
	
}





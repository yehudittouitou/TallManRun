#include "WalkingState.h"
#include "JumpingState.h"
#include "TurnLeftState.h"
#include "TurnRightState.h"
#include "Player.h"
TurnRightState::TurnRightState()
{
}

//------------------------------------------------------------   
unique_ptr<State> TurnRightState::handleInput(sf::Event event)const
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
void TurnRightState::execute(Player& player)
{
	//move right
	if (player.getPic().getPosition().x < 1100)
	{
		player.getPic().move({ float(1000 * m_clock.getElapsedTime().asSeconds()),0 });
	}
	// back to walking state
	player.changeState(std::make_unique<WalkingState>());
}
//--------------------------------------------------------------------
void TurnRightState::enter(Player& player)
{
	
	
}





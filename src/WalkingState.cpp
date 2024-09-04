#include "WalkingState.h"
#include "JumpingState.h"
#include "TurnLeftState.h"
#include "TurnRightState.h"
#include "Player.h"
WalkingState::WalkingState()
{
}

//------------------------------------------------------------   
unique_ptr<State> WalkingState::handleInput(sf::Event event)const
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

//--------------------------------------------------------------------
void WalkingState::enter(Player& player)
{
	//in walking state the player must be in 
	player.getPic().setPosition(player.getPic().getPosition().x, POS_OF_PLAYER_Y);
	
}





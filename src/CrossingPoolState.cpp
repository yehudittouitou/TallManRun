#include "CrossingPoolState.h"
#include "Player.h"
CrossingPoolState::CrossingPoolState(const int& picnum,sf::Sprite& pool)
	:m_picNum(picnum),m_poolPic(pool)
{	
}
//-----------------------------------------------------------------
CrossingPoolState::~CrossingPoolState()
{
}
//---------------------------------------------
unique_ptr<State> CrossingPoolState::handleInput(sf::Event)const
{
	// you can't change state in the middle of this state!
	return nullptr;
}
//-----------------------------
void CrossingPoolState::execute(Player& player)
{
	// checks if the player pic still touch the pool pic
	if (!(m_poolPic.getGlobalBounds().contains({ player.getPic().getPosition().x,player.getPic().getPosition().y - (player.getPic().getGlobalBounds().height / 4) })))
	{
		// back to walking state
		player.changeState(std::make_unique<WalkingState>());
		// change picture to walking pic
		player.changePicture(player.getHight() / 10);
		player.changeAnimation();
	}
}
//-----------------------------------------
void CrossingPoolState::enter(Player& player)
{
	// change pic according to how he cross (swim or on boat)
	player.changePicture(m_picNum);
	//move to the pool
	player.getPic().setPosition({ WIDTHOFBOARD/2,740 });
}

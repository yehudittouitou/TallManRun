#include "MoveToPlayer.h"
#include "Player.h"
MoveToPlayer::MoveToPlayer(Player& player,sf::Sprite& pic, const sf::Vector2f& speed,float scale)
	:m_player(player),MoveToSpecificPos(player.getPic().getPosition(), pic, speed, scale)
{
}

MoveToPlayer::~MoveToPlayer()
{
}
void MoveToPlayer::move()
{
	//if the player is move- the target position have to change
	m_posOfTarget = m_player.getPic().getPosition();
	MoveToSpecificPos::move();
}
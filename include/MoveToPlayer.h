#pragma once
#include "MoveToSpecificPos.h"
class Player;
class MoveToPlayer :public MoveToSpecificPos
{
public:
	MoveToPlayer(Player& player, sf::Sprite& pic,const sf::Vector2f& speed = { float(2),float(2) }, float scale = 1.002);
	virtual ~MoveToPlayer();
	virtual void move()override;

private:
	Player& m_player;  //player 
};
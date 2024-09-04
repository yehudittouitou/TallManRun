#pragma once
#include "MoveBehavior.h"
#include <iostream>
class MoveToSpecificPos : public MoveBehavior
{
public:
	MoveToSpecificPos(const sf::Vector2f& pos, sf::Sprite&, const sf::Vector2f& speed = { 5.f,5.f }, const float& scale = 1);//////player&
	virtual ~MoveToSpecificPos();
	virtual void move()override;

protected:
	sf::Vector2f m_posOfTarget;
	
};

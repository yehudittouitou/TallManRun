#pragma once 
#include "MoveBehavior.h"
enum MoveDirection
{
	LEFT=-1,STRAIGHT,RIGHT
};
//----------------------------
class MoveSideways:public MoveBehavior
{
public:
	MoveSideways(const MoveDirection& dir, sf::Sprite& pic, const sf::Vector2f& speed={ float(0.01),float(0.01 )});
	virtual ~MoveSideways();
	virtual void move()override;

private:
	MoveDirection m_direction; //direction
};


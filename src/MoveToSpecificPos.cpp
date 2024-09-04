#include "MoveToSpecificPos.h"



MoveToSpecificPos::MoveToSpecificPos(const sf::Vector2f& pos,sf::Sprite& pic, const sf::Vector2f& speed, const float& scale)
	:MoveBehavior(pic,speed,scale), m_posOfTarget(pos)
{
}

MoveToSpecificPos::~MoveToSpecificPos()
{
}

void MoveToSpecificPos::move()
{
	if (m_Clock.getElapsedTime().asSeconds() > 0.007)
	{
		//scale the picture
		m_picture.scale({ m_scale,m_scale });
		m_Clock.restart();
	}
	// the ratio between the distance of x and y
	float ratio = 1;
	// how much to move in x
	float x=0;
	// how much to move in y
	float y=0;
	// the distance between target pos to object pos (x)
	float distanceX = m_posOfTarget.x - m_picture.getPosition().x;
	// the distance between target pos to object pos (y)
	float distanceY = m_posOfTarget.y - m_picture.getPosition().y;

	//check the distance not zero (cant divide by zero)
	if (distanceX != 0)
	{
		ratio = std::abs(distanceY / distanceX);
		//calculate how much to move in x
		x = m_speed.x / distanceX * std::abs(distanceX);
	}
	//check the distance not zero (cant divide by zero)
	if (distanceY != 0)
		//calculate how much to move in y
		y = ratio * m_speed.y / distanceY * std::abs(distanceY);

	// move the picture
	m_picture.move({ x,y });
	
}

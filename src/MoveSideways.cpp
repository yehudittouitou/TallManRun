#include "MoveSideways.h"

MoveSideways::MoveSideways(const MoveDirection& dir, sf::Sprite& pic, const sf::Vector2f& speed)
	:MoveBehavior(pic, speed,float(0.02)),m_direction(dir)
{
}
//------------------------------------------
MoveSideways::~MoveSideways()
{
}
//----------------------------------------------
void MoveSideways::move()
{

	if (m_Clock.getElapsedTime().asSeconds() >= 0.05)
	{
		// scale picture
		m_picture.scale({float(1+( m_scale)),float(1+(m_scale) )});

		// move according to the direction and speed
		m_picture.move({ float(m_direction*m_speed.x/1.5 ),m_speed.y });

		// add speed
		m_speed += sf::Vector2f{ 0.08,0.1 };

		//restart move clock
		m_Clock.restart();
	}
}
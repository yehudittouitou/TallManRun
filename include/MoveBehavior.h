#pragma once
#include <SFML/Graphics.hpp>
class MoveBehavior
{
public:
	MoveBehavior(sf::Sprite&, const sf::Vector2f&, const float&);
	virtual ~MoveBehavior() {};
	virtual void move() = 0;

protected:
	sf::Sprite& m_picture;   // object picture      
	sf::Vector2f m_speed;    // move speed
	sf::Clock    m_Clock;    // clock for move
	float m_scale;           // how much to scale
};
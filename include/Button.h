#pragma once
#include "Object.h"
class Button :public Object
{
public:
	Button(const int, const sf::Vector2f& ,const sf::Vector2f&);
	~Button();
	void changeButtonColor(const sf::Color&);

};
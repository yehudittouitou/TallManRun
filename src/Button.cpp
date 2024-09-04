#include "Button.h"
Button::Button(const int buttonPic,const sf::Vector2f& location,const sf::Vector2f& size)
	:Object(buttonPic,location,size)
{
}
//----------------------------------
Button::~Button(){}
//---------------------------------
void Button::changeButtonColor(const sf::Color& color)
{
	// change the color of the button
	m_picture[m_curIndex].setColor(color);
}
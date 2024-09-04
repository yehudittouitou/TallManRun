#include "myText.h"
myText::myText(const std::string& string, const int& fontType, const sf::Color& color, const sf::Color& colorOutline, const sf::Vector2f& pos, const int& size, const int& Thickness)
	:m_string(string)
{
    m_text.setFont(ResourceManeger::getResourceManeger().getFont(fontType));
    m_text.setCharacterSize(size);
    m_text.setString(m_string);
    m_text.setPosition(pos);
    m_text.setOutlineThickness(Thickness);
    m_text.setColor(color);
    m_text.setOutlineColor(colorOutline);
    
}
//--------------------------------------------------------
myText::~myText()
{
}
//-----------------------------
void myText::drawText()
{
    ResourceManeger::getResourceManeger().getWindow().draw(m_text);
}
//---------------------------------------------------
void myText::setString(const std::string& string)
{
    m_string = string;
    m_text.setString(m_string);
}
//----------------------------------------------------
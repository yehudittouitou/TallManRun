#include "SizeChanger.h"
#include "Player.h"

SizeChanger::SizeChanger(char sign, int num, const int& numpic)
	:RoadObject(numpic, { 15,20 }),m_num(num)
{
	m_text.setFont(ResourceManeger::getResourceManeger().getFont(FONT1));
	m_text.setString(sign+std::to_string(m_num));
}

SizeChanger::~SizeChanger()
{
}
//-----------------------------------------------
void SizeChanger::calculateNewSize(Player& player)
{
	player.changeSize(m_num);
}
//----------------------------------------------------
void SizeChanger::drawObject()
{
	// draw the object
	Object::drawObject();
	
	// scale and move the text accirding to the object size
	sf::Vector2f size = { m_picture[m_curIndex].getGlobalBounds().width / 3, m_picture[m_curIndex].getGlobalBounds().height / 4 };
	m_text.scale({ size.x / m_text.getGlobalBounds().width,size.y / m_text.getGlobalBounds().height });
	m_text.setPosition({( m_picture[m_curIndex].getGlobalBounds().left + m_picture[m_curIndex].getGlobalBounds().width / 2)-m_text.getGlobalBounds().width/2, m_picture[m_curIndex].getGlobalBounds().top +( m_picture[m_curIndex].getGlobalBounds().height / 4)});
	
	// draw the text
	ResourceManeger::getResourceManeger().getWindow().draw(m_text);
}
//-----------------------------------------------------------------------------


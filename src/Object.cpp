#include "Object.h"
Object::Object(const int numPic, const sf::Vector2f& pos, const sf::Vector2f& size,const int& vectorSize , const sf::Vector2f& toDiv )
{
	//num of picture
	m_picture.resize(vectorSize);
	//add picture
	addPic(numPic, pos, size, 0,toDiv);
}
//--------------------------------
Object::Object(const int& vectorSize)
{
	//num of picture
	m_picture.resize(vectorSize);
}
//----------------------------------------------------------------------------------------------------
void Object::addPic(const int numPic, const sf::Vector2f& position, const sf::Vector2f& size,const int & i, const sf::Vector2f& toDiv)
{
	if (i < m_picture.size())
	{
		m_picture[i].setTexture(ResourceManeger::getResourceManeger().getPic(numPic));
		m_picture[i].scale({ size.x / m_picture[i].getLocalBounds().width,size.y / m_picture[i].getLocalBounds().height });
		m_picture[i].setPosition(position);
		setRectPic(toDiv, i);
	}
}
//---------------------------------------------------------------------------------
void Object::addPic(const int numPic, const sf::Vector2f& position, const sf::Vector2f& size, const int& i, const sf::Vector2f& divToOrigion, const sf::Vector2f& toDiv)
{
	if (i < m_picture.size())
	{
		addPic(numPic, position, size, i, toDiv);
		m_picture[i].setOrigin({ (m_picture[i].getLocalBounds().width / divToOrigion.x), m_picture[i].getLocalBounds().height / divToOrigion.y });
	}
}
//-----------------------------------
void Object::drawObject()
{
	//draw 
	ResourceManeger::getResourceManeger().getWindow().draw(m_picture[m_curIndex]);
}
//--------------------------------------------
sf::Sprite& Object::getPic()
{
	return m_picture[m_curIndex];
}
//------------------------------
void Object::changePicture(const int& i)
{
	if (i < m_picture.size())
	{
		//give the position of the current picture to the new picture
		m_picture[i].setPosition(m_picture[m_curIndex].getPosition());
		//update the curent index
		m_curIndex = i;
	}
}
//-----------------------------------
void Object::setRectPic(const sf::Vector2f& toDiv,const int& i)
{
	//rect the picture
	m_picture[i].setTextureRect(sf::IntRect(0, 0,int (m_picture[i].getLocalBounds().width/toDiv.x),int( m_picture[i].getLocalBounds().height/ toDiv.y)));
}
 
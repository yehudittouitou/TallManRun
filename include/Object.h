#pragma once
#include "ResourceManeger.h"
#include "MatchIndexPlayerPic.h"
#include "Factory.h"
class Object
{
public:
	Object(const int numPic, const sf::Vector2f& position, const sf::Vector2f& size, const int& vectorSize = 1, const sf::Vector2f& toDiv = { 1,1 });
	Object(const int& vectorSize);
	virtual ~Object() {};
	void addPic(const int numPic, const sf::Vector2f& position, const sf::Vector2f& size, const int&, const sf::Vector2f& toDiv = { 1,1 });
	void addPic(const int numPic, const sf::Vector2f& position, const sf::Vector2f& size, const int&, const sf::Vector2f& divToOrigion, const sf::Vector2f& toDiv );
	virtual void drawObject();
	sf::Sprite& getPic();
	void changePicture(const int&);
	void setRectPic(const sf::Vector2f& size,const int& i = 0);
protected:
	vector<sf::Sprite> m_picture;  //vector of picture 
	int m_curIndex = 0;            // the curent index of picture
};


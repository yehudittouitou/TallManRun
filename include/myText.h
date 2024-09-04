#pragma once
#include "ResourceManeger.h"
//#include <string>
//#include <iostream>
class myText
{
public:
	myText(const std::string& ,const int &,const sf::Color&, const sf::Color& colorOutline,const sf::Vector2f& pos,const int& size,const int & Thickness=0);
	~myText();
	void drawText();
	void setString(const std::string& string);
private:
	sf::Text m_text;
	std::string m_string;
};


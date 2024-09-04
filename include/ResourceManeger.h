#pragma once 
#include <SFML/Audio.hpp>
#include <vector>
#include "MatchSound.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "MatchPic.h"
#include "MatchFont.h"
const int WIDTHOFBOARD = 1350;
const int LENGHOFBOARD = 950;
//------------------------------------------------
class ResourceManeger
{
public:
	~ResourceManeger() = default;
	static ResourceManeger& getResourceManeger()
	{
		static ResourceManeger m_resourceManeger;
		return m_resourceManeger;
	}
	
	sf::Texture& getPic(const int&);
	sf::Font& getFont(const int &text);
	sf::RenderWindow& getWindow();
	sf::SoundBuffer& getSound(const int &sound);
	void playCollisionSound(const int& whichSound);
	void playBackGroundSound(const int& whichSound);
	void stopBackGroundSound();
private:
	void loadTexture();
	void loadFont();
	void loadSound();
	ResourceManeger();
	ResourceManeger(const ResourceManeger&) = default;
	std::vector <sf::Texture> m_picture ;
	sf::RenderWindow m_window;
	std::vector<sf::SoundBuffer> m_Sound;
	std::vector<sf::Font> m_font;
	sf::Sound m_sound;
	sf::Sound m_BackGroundSound;
};
//-----------------------------------------------------



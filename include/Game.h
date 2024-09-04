#pragma once
#include"Level.h"
#include "Menu.h"
#include "myText.h"
const int NUMOFLEVELS = 3;
class Game
{
public:
	Game();
	~Game();
	void drawWelcomeScreen();
	void runOnMenu();
	void startGame();
	void drawGame();
	bool startLevel();
	void exit() { ResourceManeger::getResourceManeger().getWindow().close();	std::exit(EXIT_SUCCESS);}
private:
	Menu m_menu;                               // menu
	sf::Sprite m_welcomeBackground;            // welcome picture
	sf::Sprite m_background;                   // background picture
	Object m_boy;                              // boy 
	std::unique_ptr<Animation> m_boyAnima;     // waving boy animation 
	std::unique_ptr<Level> m_level;            // pointer to level
	int m_Record=0;                            // record
	Button m_startButton;                      // start game button
	int m_numOfLevel = 1;                      // level num
	sf::Sound m_Melody;                        // music
	myText m_textButton;
	myText m_textLevel;
	myText m_textRecord;
};
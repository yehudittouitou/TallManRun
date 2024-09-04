#pragma once
#include "NewGame.h"
#include "Help.h"
#include "Exit.h"

using namespace std;
typedef pair<Button, unique_ptr<Command> > option;

enum Activation
{
	NOACTIVATION=-1,NEWGAME = 0,HELPACTION, EXIT
};
class Menu
{
public:
	Menu(Game& game);
	~Menu();
	Activation findButton(const sf::Vector2f&) ;
	void drawMenu();
	void deleteColors();
	void run();
private:
	vector<option> m_options;  //vector of options on menu
};


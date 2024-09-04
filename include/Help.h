#pragma once
#include "Command.h"
#include "Button.h"
class Help: public Command
{
public:
	Help();
	virtual ~Help()override;
	void draw();
	virtual void execute()override;
private:

	sf::Sprite m_instructionPic;    //pic of instructions
	Button m_goBackButton;          //button of go back

};


#pragma once
#include "Object.h"
#include "Animation.h"
#include <memory>
#include "State.h"
#include "WalkingState.h"
class InformationDisplay;
const int MAX_LIVE_POSIBLLE = 3;
const int POS_OF_PLAYER_Y = 800;
const int POS_OF_PLAYER_X = 650;
class Player : public Object
{
public:
	Player(InformationDisplay&);
	virtual ~Player();
	void updateAndMove();
	void draw();
	void HandleClick(const sf::Event& Event);
	void changeAnimation();
	int getNumOfCoin()const;
	int getHight()const;
	void changeState(std::unique_ptr< State>);
	void addCoin();
	void addLive();
	void lessLive();
	bool isAlive()const;
	void changeSize(const int& num=0);
	bool isTallEnough(const int& hight)const;
	bool isHasSuperPower()const;
	void setSuperPowerMode();
	bool isHasMagnet()const;
	void setMagnetMode();
	bool isHasBoat()const;
	void setBoatMode(const bool&);
	bool isGetToFinishLine()const;
	void GetToFinishLine();
private:
	int m_lives=3;                             // num of lives
	int m_coins=0;                             // num of collected coins
	bool m_isHasBoat=false;                    // is the player has boat
	bool m_isHasSuperPower = false;            // is the player has superpower
	bool m_isHasMagnet = false;                // is the player has magnet
	bool m_getToFinishLine = false;            // is the player get to the finish line
	int m_height = 30;                         // the height of the player
	std::unique_ptr<Animation> m_animation;    // animation
	std::unique_ptr<State> m_state;            // player state
	InformationDisplay& m_informationDisplay;  // information (need to update live, coins...)                      
	sf::Clock m_MagnetClock;                   // clock to magnet
	sf::Clock m_SuperPowerClock;               // clock to super power
	
};


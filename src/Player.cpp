#include "Player.h"
#include "Level.h"
Player::Player(InformationDisplay& info)
	:Object(NUM_OF_PLAYER_PIC), m_informationDisplay(info)
{
	// add picture of walking player in all size
	int j = PLAYER_WALK;
	float hight = 280;
	for (int i = PLAYER0; j< NUM_OF_WAKING; i++, j++, hight += 34)
	{
		addPic(i, { POS_OF_PLAYER_X,POS_OF_PLAYER_Y }, { 1000,hight }, j, { 2,1 }, { 8,1 });
	}

	// add picture of player sit on boat
	addPic(SIT, { POS_OF_PLAYER_X,POS_OF_PLAYER_Y }, { 270,270 }, SIT_ON_BOAT, { 2,1 }, { 1,1 });
	
	// add picture of player cross pool
	addPic(INPOOL, { POS_OF_PLAYER_X,POS_OF_PLAYER_Y }, { 515.4,170 }, IN_POOL, { 2,1 }, { 2,1 });
	
	// add picture of magnet above player head                                
	addPic(MAGNETPLAYER, { POS_OF_PLAYER_X,POS_OF_PLAYER_Y }, { 70,41.5 }, HAVE_MAGNET, { 2,1 }, { 1,1 });
	
	// add picture of circle under the player legs
	addPic(SUPERPOWERPLAYER, { POS_OF_PLAYER_X,POS_OF_PLAYER_Y }, { 300,100 }, HAVE_SUPERPOWER, { 2,1 }, { 1,1 });
	
	// Add picture of player fail
	addPic(FAILPIC, { POS_OF_PLAYER_X,POS_OF_PLAYER_Y }, { 600,600 }, PLAYER_FAIL, { 2,1 }, { 1,1 });
	
	// the curent size of player
	changePicture(m_height/10);
	changeAnimation();
	
	// start in walking state
	m_state = std::make_unique<WalkingState>();
	
}

//---------------------------------------------------------------------
Player::~Player()
{
}
//---------------------------------------------------------
void Player::changeSize(const int& num )
{
	//if he get to the min size - he die
	if (m_height + num < 0)   
		lessLive();
	else
	{
		//if he get to the max size
		if (m_height + num > 90)       
			m_height = 90;

		//add/less size
		else
			m_height += num;           

		changePicture(m_height / 10);
		changeAnimation();
	}
		
}
//----------------------------------------------------
bool Player::isTallEnough(const int& hight)const
{
	return m_height >= hight;
}
//--------------------------------------
void Player::updateAndMove()
{
	// rect next pic
	m_animation->setRect();
	// execute the state
	m_state->execute(*this);
	//if time of superpower is over 
	if (m_isHasSuperPower && m_SuperPowerClock.getElapsedTime().asSeconds() > 10)
		m_isHasSuperPower = false;
	//if time of magnet is over 
	if (m_isHasMagnet && m_MagnetClock.getElapsedTime().asSeconds() > 15)
		m_isHasMagnet = false;
}
//----------------------------------------
void Player::draw()
{
	if (m_isHasSuperPower)
	{
		// draw circle of super power
		m_picture[HAVE_SUPERPOWER].setPosition({ m_picture[m_curIndex].getPosition().x,830 });
		ResourceManeger::getResourceManeger().getWindow().draw(m_picture[HAVE_SUPERPOWER]);
	}

	// draw player
	drawObject();

	if (m_isHasMagnet)
	{
		// draw magnet above player head
		m_picture[HAVE_MAGNET].setPosition({ m_picture[m_curIndex].getPosition().x,m_picture[m_curIndex].getPosition().y- m_picture[m_curIndex].getGlobalBounds().height });
		ResourceManeger::getResourceManeger().getWindow().draw(m_picture[HAVE_MAGNET]);
	}
}
//---------------------------------------------------
void Player::HandleClick(const sf::Event& Event)
{
	changeState(m_state->handleInput(Event));
}
//-------------------------------------------------
void Player::changeAnimation()
{
	//if he walk
	if (m_curIndex < NUM_OF_WAKING)
		m_animation = std::make_unique<Animation>(m_picture[m_curIndex], sf::Vector2i{ 8,0 }, 0.08);
}
//---------------------------------------
int Player::getNumOfCoin()const
{
	return m_coins;
}
//--------------------------------------------------
int Player::getHight()const
{
	return m_height;
}
//------------------------------------------------------------
void Player::changeState(std::unique_ptr<State> state)
{
	if (state)
	{
		m_state = std::move(state);
		m_state->enter(*this);

	}
}
//---------------------------------------------------------------
bool Player::isHasBoat() const
{
	return m_isHasBoat;
}
//---------------------------------------------------------------------
void Player::setBoatMode(const bool& mode)
{
	m_isHasBoat = mode;
	m_informationDisplay.updateInformation(m_coins, m_lives, m_isHasBoat);
}
//---------------------------------------
bool Player::isGetToFinishLine() const
{
	return m_getToFinishLine;
}
//---------------------------------
void Player::GetToFinishLine()
{
	m_getToFinishLine = true;
}
//--------------------------------------------------------
void Player::addCoin()
{
	m_coins++;
	m_informationDisplay.updateInformation(m_coins, m_lives, m_isHasBoat);
}
//--------------------------------------------------------------
void Player::addLive()
{
	if (m_lives <= MAX_LIVE_POSIBLLE)
	{
		m_lives++;
		m_informationDisplay.updateInformation(m_coins, m_lives, m_isHasBoat);
	}
}
//----------------------------------------------------------------
void Player::lessLive()
{
	m_lives--;
	m_informationDisplay.updateInformation(m_coins, m_lives, m_isHasBoat);
	ResourceManeger::getResourceManeger().playCollisionSound(LESSLIVESOUND);
	ResourceManeger::getResourceManeger().getWindow().draw(m_picture[PLAYER_FAIL]);
	ResourceManeger::getResourceManeger().getWindow().display();  //print messege
	sf::sleep(sf::seconds(1));
	
	//return to original mode
	changePicture(3);
	changeAnimation();
	changeState(std::make_unique<WalkingState>());
	m_picture[m_curIndex].setPosition({ POS_OF_PLAYER_X,POS_OF_PLAYER_Y });                        
	
	
}
//-----------------------------------------------------------------
bool Player::isAlive()const
{
	return m_lives>0;
}
//--------------------------------------
bool Player::isHasSuperPower()const
{
	return m_isHasSuperPower;
}
//------------------------------------------
void Player::setSuperPowerMode()
{
	m_isHasSuperPower = true;
	m_SuperPowerClock.restart();
}
//---------------------------------------------
bool Player::isHasMagnet()const
{
	return m_isHasMagnet;
}
//-------------------------------------------------
void Player::setMagnetMode()
{
	m_isHasMagnet = true;
	m_MagnetClock.restart();
}
//--------------------------------------------------

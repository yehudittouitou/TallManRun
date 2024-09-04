#include "Level.h"
Level::Level(const int & numoflevel)
	:m_board(numoflevel),m_information(),m_Player(m_information)
{
	m_information.updateInformation( 0, NUM_OF_SHOW_HERAT, false);
}
//---------------------------------------
Level::~Level()
{
}
//----------------------------------------------
void Level::draw()
{
	ResourceManeger::getResourceManeger().getWindow().clear();
	// draw board
	m_board.draw();
	// draw information display board
	m_information.draw();
	// draw palyer
	m_Player.draw();
	// show screen
	ResourceManeger::getResourceManeger().getWindow().display();
}
//---------------------------------------------------------------------------------------
bool Level::run(int & record)
{

	auto event = sf::Event{};
	while (ResourceManeger::getResourceManeger().getWindow().isOpen())
	{
		// if the player is dead
		if (!m_Player.isAlive())
		{
			ResourceManeger::getResourceManeger().playCollisionSound(FAILSOUND);
			updateRecord(record);
			return false;
		}
		// if the player get to the finush line!
		if (m_Player.isGetToFinishLine())
		{
			ResourceManeger::getResourceManeger().playCollisionSound(WINSOUND);
			updateRecord(record);
			return true;
		}
		// add new object
		m_board.AddNewObject();
		// draw level
		draw();
		// update board and player
		updateAndMoveBoardAndPlayer();
		// proceess colision between player and objects
		m_board.Collision(m_Player);
		
		while (ResourceManeger::getResourceManeger().getWindow().pollEvent(event))
		{
			switch (event.type)
			{
				case sf::Event::Closed:  ResourceManeger::getResourceManeger().getWindow().close();
					exit(EXIT_SUCCESS);
				// handle user click
				case sf::Event::KeyPressed: m_Player.HandleClick(event);
			}
		}
	}
	return true;
}
//---------------------------------------------------
void Level::updateRecord(int& record)
{
	// if he colected more coins than the record
	if (m_Player.getNumOfCoin() > record)
		//change the record
		record = m_Player.getNumOfCoin();
}
//----------------------------------------------
void Level::updateAndMoveBoardAndPlayer()
{
	// move all objects in board
	m_board.moveAllBoard();
	// if the player has magnet- magnetize coins to it
	if (m_Player.isHasMagnet())
		m_board.magnetizeCoins(m_Player);
	// move & update player 
	m_Player.updateAndMove();
}


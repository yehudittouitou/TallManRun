#include "Board.h"
#include "Factory.h"
#include "Player.h"
#include "Coin.h"
#include "MoveToPlayer.h"
Board::Board(const int & numOfLevel)
	: m_lines(),m_numOfLevel(numOfLevel)
{
	//picture of the sky
	m_sky.setTexture(ResourceManeger::getResourceManeger().getPic(SKY));	
	
	//fill the all objects vector with the vectors
	m_AllObjects = { &m_RoadObjects,&m_takenObjects,&m_clouds };
}
//------------------------------------------------------------------
void  Board::draw()
{
	// draw the road lines
	m_lines.drawObject();

	// draw the sky
	ResourceManeger::getResourceManeger().getWindow().draw(m_sky);

	// run on all the objects vectors
	for (auto ObjectVector : m_AllObjects)
	{
		// draw all objects
		for (int i = ObjectVector->size() - 1; i >= 0; i--)
			(*ObjectVector)[i]->drawObject();
	}
}
//---------------------------------------------------------------------------------
void Board::AddNewObject()
{
	// if its time to add objects
	if (m_AddObjectsClock.getElapsedTime().asSeconds() >= 1.5)
	{
		//add clouds
		AddClouds();

		// if he's not finish to create all objects
		if (m_numOfCreatedObjects <= Factory::getNumOfCreateObjects()[m_numOfLevel-1])
		{
			// create random object
			if(m_numOfCreatedObjects < Factory::getNumOfCreateObjects()[m_numOfLevel-1])
				m_RoadObjects.emplace_back(move(Factory::createRandomly(m_numOfLevel-1)));

			// create the finish line object
			else m_RoadObjects.emplace_back(move(Factory::create(O_FINISH)));

			// increase the objects num
			m_numOfCreatedObjects++;
		}
		m_AddObjectsClock.restart();
	}
}
//-----------------------------------------------------------------
void Board::AddClouds()
{
	// add 2 clouds in left and right
	m_clouds.emplace_back(move(Factory::create(O_CLOUD)));
	m_clouds.emplace_back(move(Factory::create(O_CLOUD)));
}
//-------------------------------------------------------------
void Board::moveTotakenObjectsVector(const int& i)
{
	// move the object to the vector of taken objects
	m_takenObjects.emplace_back(std::move(m_RoadObjects[i]));

	// delete the pointer from the vector 
	m_RoadObjects.erase(m_RoadObjects.begin() + i);
}
//-----------------------------------------------------
void Board::Collision(Player& player)
{
	// run on the vector of road objects
	for (int i = 0;i< m_RoadObjects.size(); i++)
	{
		// cheak if the object is colide with player
		if (m_RoadObjects[i]->isColideWithPlayer(player))
		{
			// process the collision
			processCollision(player, *m_RoadObjects[i]);
			// move the objects to vector if taken objects
			moveTotakenObjectsVector(i);
			break;
		}	
	}
}
//--------------------------------------------------------------
void Board::moveAllBoard()
{
	// move the lines on road
	m_lines.moveLines();

	// run on all the objects vectors
	for (auto ObjectVector : m_AllObjects)
	{
		// run fron the end to the begining
		for (int i = ObjectVector->size() - 1; i >= 0; i--)
		{
			// move object
			(*ObjectVector)[i]->move();

			// cheak if the object is done, and if it is- delete it from vector 
			if ((*ObjectVector)[i]->isFinish())
				ObjectVector->erase(ObjectVector->begin() + i);
		}
	}
}
//------------------------------------------------------------
void Board::magnetizeCoins(Player& player)
{
	for (int i = 0; i < m_RoadObjects.size() ; i++)
	{
		// if the object is coin
		if (typeid(*m_RoadObjects[i]) == typeid(Coin))
		{
			// if the coin is relativetly at the begining of the road 
			if (m_RoadObjects[i]->getPic().getPosition().y > 400 && m_RoadObjects[i]->getPic().getPosition().y<800)
			{
				// convert the pointer to coin
				Coin& coin = dynamic_cast<Coin&>(*m_RoadObjects[i]);

				// change the move behavior to move towards the player
				coin.changeMoveBehavior(std::make_unique<MoveToPlayer>(player, coin.getPic()));
			}
		}
	}
}
//---------------------------------------------------------


#include "Factory.h"
#include "RoadObject.h"
//--------------------------------------------------------
// create function for specific object
//----------------------------------------------------------------------------------
std::unique_ptr<RoadObject>  Factory::create(const int& type)
{
	// create object
	if(type<OBJECTS_NUM)
		return getMyObjects()[type]();
	return nullptr;
}
//-------------------------------------------------------------------
// create function for random object
//------------------------------------------------------------------
std::unique_ptr<RoadObject> Factory::createRandomly(const int& numOfLevel)
{
	// fill the FrequencyRatio- just once!
	static bool isFill = false;
	if (!isFill)
	{
		fillFrequencyRatio();
		isFill = true;
	}
	// rand object 
	int	type = getFrequencyRatio()[numOfLevel](getGen());
	// create object
	return std::move(Factory::create(type));
}
//---------------------------------------------------------------------------------
// register object to the factory
//---------------------------------------------------------------------------
bool Factory::registerit( const int&  type, CreateFunction func)
{
	getMyObjects()[type]=func;
	return true;
}
//----------------------------------------------------------------------
// fill vector of direction position and origin
//--------------------------------------------------------------------
void Factory::fillPosOnRoad()
{
	srand(time(0));
	getVectorPosOnRoad()[LEFT_SKY] = (posOnRoad(LEFT,position ( sf::Vector2f(475, 150), sf::Vector2f(1, 1))));          /*left2*/
	getVectorPosOnRoad()[LEFT_ROAD]=(posOnRoad(LEFT, position (sf::Vector2f(650, 210), sf::Vector2f(1, 1))));           /*left1*/
	getVectorPosOnRoad()[MIDDLE_ROAD]=(posOnRoad(STRAIGHT, position (sf::Vector2f(675, 210), sf::Vector2f(0.5, 1))));   /*stright*/
	getVectorPosOnRoad()[RIGHT_ROAD]=(posOnRoad(RIGHT, position (sf::Vector2f(700, 210), sf::Vector2f(0, 1))));         /*right1*/
	getVectorPosOnRoad()[RIGHT_SKY]=(posOnRoad(RIGHT, position( sf::Vector2f(875, 150), sf::Vector2f(0, 1))));          /*right2*/
}
//---------------------------------------------------------
// fill the Frequency Ratio of the levels
//--------------------------------------------------------------
void Factory::fillFrequencyRatio()
{



	static mt19937 gen(getRandomDevice()());
	getGen() = gen;
	vector<vector<int>> temp; 
	

	vector<int> level1 = {/*pool*/ 0,/*MAGNET*/2,/*HEART*/3,/*FENCE*/5,/*BOMB*/5,/* BOAT*/0,/* SPACESHIP*/0,/*COIN*/8,/*SIZECHANGERADD*/5,/*SIZECHANGERDIV*/5,/*SIZECHANGERLESS*/5,/*SIZECHANGERDBL*/5,/*SUPERPOWER*/0 };
	vector<int> level2 = {/*pool*/ 5,/*MAGNET*/5,/*HEART*/4,/*FENCE*/5,/*BOMB*/5,/* BOAT*/3,/* SPACESHIP*/0,/*COIN*/10,/*SIZECHANGERADD*/5,/*SIZECHANGERDIV*/5,/*SIZECHANGERLESS*/5,/*SIZECHANGERDBL*/5,/*SUPERPOWER*/5 };
	vector<int> level3 = {/*pool*/ 5,/*MAGNET*/5,/*HEART*/5,/*FENCE*/5,/*BOMB*/5,/* BOAT*/3,/* SPACESHIP*/3,/*COIN*/10,/*SIZECHANGERADD*/5,/*SIZECHANGERDIV*/5,/*SIZECHANGERLESS*/5,/*SIZECHANGERDBL*/5,/*SUPERPOWER*/5 };
	
	temp.emplace_back(level1);
	temp.emplace_back(level2);
	temp.emplace_back(level3);
	for (int i = 0; i < temp.size(); i++)
	{
		discrete_distribution<> FrequencyRatio(temp[i].begin(), temp[i].end());
		getFrequencyRatio().emplace_back( FrequencyRatio);
	}
}
//-----------------------------------------------------------------------
// get pos and origion on road
//--------------------------------------------------------------------------------
posOnRoad& Factory::getPosOnRoad(const int& type)
{
	// fill pos vector just once!
	static bool isFill = false;
	if (!isFill)
	{
		fillPosOnRoad();
		isFill = true;
	}
	if(type<POS_NUM)
		return getVectorPosOnRoad()[type];
}
//------------------------------------------------------------------------
vector< int>& Factory::getNumOfCreateObjects()
{
	// fill num of objects in levels
	static vector< int> m_numOfCreateObjects;
	static bool Fill = false;
	if (!Fill)
	{
		m_numOfCreateObjects = { /*level1*/30, /*level2*/60, /*level3*/90 };
		Fill = true;
	}
	return m_numOfCreateObjects;

}
//----------------------------------------------------------------


 

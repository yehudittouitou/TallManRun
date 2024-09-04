#pragma once
#include <memory>
#include <vector>
#include <time.h>
#include <functional>
#include "MatchObjects.h"
#include "MoveSideWays.h"
#include <random>
class RoadObject;
using namespace std;
typedef function <unique_ptr<RoadObject>()> CreateFunction;
typedef vector <CreateFunction> myObjects;
typedef  std::pair<sf::Vector2f, sf::Vector2f> position;
typedef std::pair<MoveDirection, position> posOnRoad;
class Factory
{
public:
	static std::unique_ptr<RoadObject> create(const int &type);
	static std::unique_ptr<RoadObject> createRandomly(const int& numOfLevel);
	static bool registerit(const int& level, CreateFunction);
	static void fillPosOnRoad();
	static void fillFrequencyRatio();
	static posOnRoad& getPosOnRoad(const int& type);
	static vector< int>& getNumOfCreateObjects();

private:
	static myObjects & getMyObjects()
	{
		static myObjects m_Objects(OBJECTS_NUM);
		return m_Objects;
	}
	static vector<posOnRoad>& getVectorPosOnRoad()
	{
		static vector<posOnRoad> m_posOnRoad(POS_NUM);
		return m_posOnRoad;
	}
	static vector<discrete_distribution<>>& getFrequencyRatio()
	{
		static vector<discrete_distribution<>> m_FrequencyRatio;
		return  m_FrequencyRatio;
	}
	static mt19937& getGen()
	{
		static mt19937 m_gen;
		return m_gen;
	}
	static random_device& getRandomDevice()
	{
		static random_device m_rd;
		return m_rd;
	}
	

};











#pragma once
#include <fstream>
#include <memory>
#include <ctime>
#include "ResourceManeger.h"
#include "RoadLines.h"
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <random>
#include "CollisionHandling.h"
#include "Cloud.h"
class Player;
class Factory;
using namespace std;
//--------------------------------------
class Board
{
public:
	Board(const int&);
	~Board() {}
	void draw();
	void AddNewObject();
	void AddClouds();
	void moveTotakenObjectsVector(const int& i);
	void Collision(Player&);
	void moveAllBoard();
	void magnetizeCoins(Player&);

private:
	vector < vector < unique_ptr < RoadObject>>*> m_AllObjects; // vector of pointers to all objects vectors
	vector < unique_ptr < RoadObject>> m_takenObjects;          // vector of objects that already colide with player
	vector< unique_ptr < RoadObject>> m_clouds;                 // vector of clouds
	vector<unique_ptr<RoadObject>>m_RoadObjects;                // vector of objects on road
	int m_numOfLevel;                                           // level number
	int m_numOfCreatedObjects=0;                                // the number of objects created
	sf::Sprite m_sky;                                           // picture of sky
	RoadLines m_lines;                                          // picture of lines (on road)
	sf::Clock m_AddObjectsClock;                                // clock the according to him we build objects  
};


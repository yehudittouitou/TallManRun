#pragma once
#include "Object.h"

#include <vector>
#include <algorithm>
#include  "MoveSideways.h"
#include "IsFinish.h"

class Player;
using namespace std;
class RoadObject :public Object
{
public:
	RoadObject(const int&, const sf::Vector2f&, const sf::Vector2f& speed = { float(0.05),float(0.01) } ,  const sf::Vector2f& toDiv = { 1,1 }, const sf::Vector2i& indexAnima = { 1,1 });
	RoadObject(const int&, const sf::Vector2f&, const	posOnRoad&, const sf::Vector2f& speed = { float(0.05),float(0.01) }, const sf::Vector2f& toDiv = { 1,1 }, const sf::Vector2i& indexAnima = { 1,1 });
	virtual ~RoadObject()=0;
	virtual bool isColideWithPlayer(Player&, const float& pos=700);
	void build(const sf::Vector2f& toDiv, const	posOnRoad& posr, const sf::Vector2i& indexAnima, const sf::Vector2f& speed);
	virtual void move();
	virtual bool isFinish()const;
	Animation& getAnimation();
	void changeMoveBehavior(unique_ptr< MoveBehavior>);
	void changeIsFinish(unique_ptr< IsFinish>);
protected:
	unique_ptr< MoveBehavior> m_move;      // pointer to move behavior
	unique_ptr< IsFinish> m_isFinish;      // pointer to cause of finish
	std::unique_ptr<Animation> m_animation;// animation
};
//------------------------

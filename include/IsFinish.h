#pragma once
#include <SFML/Graphics.hpp>
#include  "Animation.h"
#include <functional>
//----------------------------------
// futher class (using strategy)
// each class inherits will return information- whether the object has completed his work
//-----------------------------------
class IsFinish
{
public:
	IsFinish() {}
	virtual ~IsFinish(){}
	virtual bool isFinish()const=0;
private:

};
//--------------------------------------------------


class IsGetToLocation:public IsFinish
{
public:
	// the costructor gets: the picture of the objects, target position, comparision function
	IsGetToLocation(sf::Sprite& pic,const float& pos, function <bool(float,float)> func)
		:m_picture(pic),m_EndLocation(pos), m_comparisionFunc(func){}

	virtual ~IsGetToLocation(){}
	virtual bool isFinish()const override
	{
		// return if the object get to the target position or not
		return (m_comparisionFunc(m_picture.getPosition().y, m_EndLocation));
	}
private:
	function <bool(float, float)> m_comparisionFunc;  //comparision function
	sf::Sprite& m_picture;                            //the objects picture
	float m_EndLocation;                              //the target location
};
//------------------------------------------------------


class IsFinishShowAnimation :public IsFinish
{
public:
	//the constructor gets the animation of the object
	IsFinishShowAnimation(Animation& anima)
		:m_animation(anima){}

	virtual ~IsFinishShowAnimation(){}
	virtual bool isFinish()const override
	{
		// return whether the animation done or not
		return m_animation.IsDone();
	}
private:
	Animation& m_animation;
};

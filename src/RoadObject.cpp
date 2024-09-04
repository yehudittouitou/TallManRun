#include "RoadObject.h"
#include "Player.h"
// constractor for objects that rand position
//-------------------------------------------------------------------------------------------------
RoadObject::RoadObject(const int & numPic,const sf::Vector2f& size,const sf::Vector2f& speed,const sf::Vector2f& toDiv, const sf::Vector2i& indexAnima)
	:Object(numPic, { 675,210 }, size)
{
	// rand num between 2 - 4
	int i = ((rand()+numPic) % 3)+2;
	build(toDiv,Factory::getPosOnRoad(i), indexAnima,speed);
}
// constractor for objects that have to be in specific position
//-----------------------------------------------------------------------------------------------------------
RoadObject::RoadObject(const int& numPic, const sf::Vector2f& size, const	posOnRoad& pos, const sf::Vector2f& speed, const sf::Vector2f& toDiv, const sf::Vector2i& indexAnima)
	:Object(numPic, pos.second.first, size)
{
	build(toDiv,pos, indexAnima,speed);
}
//------------------------------------------
RoadObject::~RoadObject(){}
//----------------------------------
void RoadObject::build(const sf::Vector2f& toDiv, const	posOnRoad& pos, const sf::Vector2i& indexAnima, const sf::Vector2f& speed)
{
	// rect the first cut of the picture
	setRectPic(toDiv);

	// make animation
	m_animation = std::make_unique<Animation>(m_picture[m_curIndex], indexAnima);

	// set position and origion of the picture
	m_picture[m_curIndex].setPosition(pos.second.first);
	m_picture[m_curIndex].setOrigin(float(m_picture[m_curIndex].getTextureRect().width * pos.second.second.x), float(m_picture[m_curIndex].getTextureRect().height * pos.second.second.y));
	
	// set move behavior of the object
	m_move = make_unique< MoveSideways>(pos.first, m_picture[m_curIndex], speed);
	
	// set cause of finish
	m_isFinish = make_unique<IsGetToLocation>(m_picture[m_curIndex], LENGHOFBOARD, [](float a, float b) { return a >= b; });
}
//----------------------------------------------
void RoadObject::move()
{
	// rect the next part of the picture
	m_animation->setRect();
	// move the object
	m_move->move();
}
//-------------------------------------------------------------------------
bool RoadObject::isFinish()const
{
	return m_isFinish->isFinish();
}
//---------------------------------------------------------------
Animation& RoadObject::getAnimation()
{
	return *m_animation;
}
//---------------------------------------------------------------------------
void RoadObject::changeMoveBehavior(unique_ptr<MoveBehavior> newMoveBehavior)
{
	// change move behavior
	m_move = std::move(newMoveBehavior);
}
//---------------------------------------------------------------------------
void RoadObject::changeIsFinish(unique_ptr<IsFinish> isfinish)
{
	// change cause of finish
	m_isFinish = std::move(isfinish);
}
//-------------------------------------------------------------------
bool RoadObject::isColideWithPlayer( Player& player,const float& pos)
{
	//if the object past the position
	if ((m_picture[m_curIndex].getPosition().y > pos) &&
		/*if the object touch the player*/
		(m_picture[m_curIndex].getGlobalBounds().intersects(player.getPic().getGlobalBounds())))
		//colide
		return true;
	//not colide
	return false;
}

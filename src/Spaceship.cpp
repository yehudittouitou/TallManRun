#include "Spaceship.h"
#include "MoveToSpecificPos.h"
Spaceship::Spaceship()
	:RoadObject(SPACESHIP, {65,50 }, Factory::getPosOnRoad(MIDDLE_ROAD))
{
	m_picture[m_curIndex].move({ 0,-50 });
	m_move = make_unique< MoveToSpecificPos>(sf::Vector2f{ (WIDTHOFBOARD/2),0 }, m_picture[m_curIndex],sf::Vector2f(0, 0.0001),1.008);
	m_isFinish = make_unique<IsGetToLocation>(m_picture[m_curIndex], 0, [](float a, float b) { return a <= b; });
}
//--------------------------------------------------------------------------
Spaceship::~Spaceship()
{
}
//-------------------------------------------------
void Spaceship::move()
{
	// move the space ship
	RoadObject::move();
	// create shoot 
	createShoot();
	// if the bullet is exists
	if (m_shootBullet!=nullptr)
	{
		// move the bullet
		m_shootBullet->move();
		//if (m_shootBullet->isFinish())
		//	m_shootBullet.release();
	}
	
}
//----------------------------------
void Spaceship::createShoot()
{
	//if the spaceship is above the player
	if ((m_picture[m_curIndex].getGlobalBounds().width >= float(400)) && (m_shootBullet == nullptr))
	{
		// create bullet
		m_shootBullet = std::move(Factory::create(O_SHOOT));
		// give the bullet the spaceship position
		m_shootBullet->getPic().setPosition(m_picture[m_curIndex].getPosition());
	}
}
//---------------------------------
void Spaceship::drawObject()
{
	// draw spaceship
	RoadObject::drawObject();
	// draw bullet
	if(m_shootBullet !=nullptr)
		m_shootBullet->drawObject();
}
//---------------------------------------
bool Spaceship::isFinish()const
{
	// the object finish if the bullet finish
	if (m_shootBullet != nullptr)
		return m_shootBullet->isFinish();
	return false;
}
//-----------------------------------------------
RoadObject& Spaceship::getShoot()
{
	return *m_shootBullet;
}
//-----------------------------------------------------------
bool Spaceship::isColideWithPlayer(Player& player, const float& pos)
{
	// check if the bullet colide with the player
	if(m_shootBullet !=nullptr)
		return m_shootBullet->isColideWithPlayer(player, 150);
	return false;
}
//-------------------------------------
bool Spaceship::m_isRegister = Factory::registerit(O_SPACESHIP, []()-> std::unique_ptr<RoadObject> {return std::make_unique<Spaceship>(); });

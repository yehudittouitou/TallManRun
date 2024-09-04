#include "Shoot.h"
#include "MoveToSpecificPos.h"
Shoot::Shoot()
	:RoadObject(BOMB, { 424,80 }, { float(0.01),float(0.01) }, { 4,1 })
{
	m_move = make_unique<MoveToSpecificPos>(sf::Vector2f{ WIDTHOFBOARD / 2, 700 },m_picture[m_curIndex]);
	m_isFinish = make_unique<IsGetToLocation>(m_picture[m_curIndex], 700, [](float a, float b) { return a >= b; });
}

Shoot::~Shoot()
{
}
//-----------------------------------------------------------------------------
bool Shoot::m_isRegister = Factory::registerit(O_SHOOT, []()-> std::unique_ptr<RoadObject> {return std::make_unique<Shoot>(); });

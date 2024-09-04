#include "Bomb.h"

Bomb::Bomb()
	:RoadObject(BOMB, { 80.025,15 }, { float(0.01),float(0.01) }, { 4,1 })
{
}

Bomb::~Bomb()
{
}
//-----------------------------------------------------------------------------
bool Bomb::m_isRegister = Factory::registerit(O_BOMB, []()-> std::unique_ptr<RoadObject> {return std::make_unique<Bomb>(); });

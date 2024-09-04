#include "SuperPower.h"
bool SuperPower::m_isRegister = Factory::registerit(O_SUPERPOWER, []()-> std::unique_ptr<RoadObject> {return std::make_unique<SuperPower>(); });
SuperPower::SuperPower()
	:RoadObject(SUPERPOWER, { 15,15})
{
}

SuperPower::~SuperPower()
{
}

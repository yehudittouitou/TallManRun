#include "Boat.h"
Boat::Boat()
	:RoadObject(BOAT,{22.5,15})
{
}
Boat::~Boat()
{
}
//-----------------------------------------------------------------------------
bool Boat::m_isRegister = Factory::registerit(O_BOAT, []()-> std::unique_ptr<RoadObject> {return std::make_unique<Boat>(); });

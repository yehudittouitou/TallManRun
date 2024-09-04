#include "Pool.h"

Pool::Pool()
	:RoadObject(POOL, sf::Vector2f{ 70,25 },Factory::getPosOnRoad(MIDDLE_ROAD) )
{

}
//--------------------------------------------------
Pool::~Pool()
{
}
bool Pool::m_isRegister = Factory::registerit(O_POOL, []()-> std::unique_ptr<RoadObject> {return std::make_unique<Pool>(); });

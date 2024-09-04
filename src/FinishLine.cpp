#include "FinishLine.h"
bool FinishLine::m_isRegister = Factory::registerit(O_FINISH, []()-> std::unique_ptr<RoadObject> {return std::make_unique<FinishLine>(); });

FinishLine::FinishLine()
	:RoadObject(FINISH, sf::Vector2f{ 100,50 }, Factory::getPosOnRoad(MIDDLE_ROAD))
{
}

FinishLine::~FinishLine()
{
}
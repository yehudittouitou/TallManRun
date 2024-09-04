#include "Cloud.h"
Cloud::Cloud()
	:RoadObject(CLOUD, { 62,40 }, Factory::getPosOnRoad(randCloud()) , sf::Vector2f{4,0.0001})//??
{
	
}
//----------------------------------------
Cloud::~Cloud()
{
}
//------------------------------------------
int Cloud::randCloud()
{
	// the function return the cloud side - once right one left
	static bool right = true;
	if (right)
	{
		right = false;
		return RIGHT_SKY;
	}
	right = true;
	return LEFT_SKY;
}
//-----------------------------------------------------------------------------
bool Cloud::m_isRegister = Factory::registerit(O_CLOUD, []()-> std::unique_ptr<RoadObject> {return std::make_unique<Cloud>(); });


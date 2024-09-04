#include "Heart.h"
bool Heart::m_isRegister = Factory::registerit(O_HEART, []()-> std::unique_ptr<RoadObject> {return std::make_unique<Heart>(); });
//---------------------------------------------------------------------------------------------------------------------------------
Heart::Heart()
	:RoadObject(HEART, { 85.9,15 }, { float(0.01),float(0.01) }, { 6,1 }, { 6,1 })
{
}
//-------------------------------------------------------------------
Heart::~Heart()
{
}
//-------------------------------------------------

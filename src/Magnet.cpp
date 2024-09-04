#include "Magnet.h"
Magnet::Magnet()
	:RoadObject(MAGNET, { 65,10 }, { float(0.01),float(0.01) }, { 8,1 }, { 8,1 })
{

}
Magnet::~Magnet()
{
}
//-----------------------------------------------------------------------------
bool Magnet::m_isRegister = Factory::registerit(O_MAGNET, []()-> std::unique_ptr<RoadObject> {return std::make_unique<Magnet>(); });


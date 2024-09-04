#include "Fence.h"

Fence::Fence()
	:RoadObject(FENCE, { 20,15 })
{
}

Fence::~Fence()
{
}
//-----------------------------------------------------------------------------
bool Fence::m_isRegister = Factory::registerit(O_FENCE, []()-> std::unique_ptr<RoadObject> {return std::make_unique<Fence>(); });

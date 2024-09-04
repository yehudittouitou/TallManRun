#pragma once
#include "RoadObject.h"
class Pool :public RoadObject
{
public:
	Pool();
	virtual ~Pool();

private:
	static bool m_isRegister;
};
//-----------------------------------------------------------------------------


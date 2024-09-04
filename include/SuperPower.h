#pragma once
#include "RoadObject.h"
class SuperPower :public RoadObject
{
public:
	SuperPower();
	virtual ~SuperPower();

private:
	static bool m_isRegister;
};
//-----------------------------------------------------------------------------


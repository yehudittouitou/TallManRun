#pragma once
#include "RoadObject.h"
class Magnet :public RoadObject
{
public:
	Magnet();
	virtual ~Magnet();

private:
	static bool m_isRegister;
};

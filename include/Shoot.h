#pragma once
#include "RoadObject.h"
class Shoot:public RoadObject
{
public:
	Shoot();
	virtual ~Shoot();
	
private:
	static bool m_isRegister;
};
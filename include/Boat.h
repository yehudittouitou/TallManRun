#pragma once
#include "RoadObject.h"
class Boat :public RoadObject
{
public:
	Boat();
	virtual ~Boat()override;

private:
	static bool m_isRegister;
};


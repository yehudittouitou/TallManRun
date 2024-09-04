#pragma once
#include "RoadObject.h"
class Fence :public RoadObject
{
public:
	Fence();
	virtual ~Fence()override;

private:
	static bool m_isRegister;
};

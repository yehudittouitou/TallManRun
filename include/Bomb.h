#pragma once
#include "RoadObject.h"
class Bomb :public RoadObject
{
public:
	Bomb();
	virtual ~Bomb()override;

private:
	static bool m_isRegister;
};

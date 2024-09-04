#pragma once
#include "RoadObject.h"
class Coin :public RoadObject
{
public:
	Coin();
	virtual ~Coin()override;
private:
	static bool m_isRegister;
};

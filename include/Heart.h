#pragma once
#include "RoadObject.h"
class Heart :public RoadObject
{
public:
	Heart();
	virtual ~Heart()override;
private:

	static bool m_isRegister;
};

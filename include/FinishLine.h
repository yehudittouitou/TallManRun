#pragma once
#include "RoadObject.h"
class FinishLine:public RoadObject
{
public:
	FinishLine();
	virtual ~FinishLine()override;

private:
	static bool m_isRegister;

};


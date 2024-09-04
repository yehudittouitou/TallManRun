#pragma once
#include "RoadObject.h"
class Cloud :public RoadObject
{
public:
	Cloud();
	virtual ~Cloud()override;
	static int randCloud(); 
private:
	static bool m_isRegister;
};
#pragma once
#include "SizeChanger.h"
class SizeChangerDivide:public SizeChanger
{
public:
	SizeChangerDivide();
	virtual ~SizeChangerDivide() {};

private:
	static bool m_isRegister;
};
#pragma once
#include "SizeChanger.h"
class SizeChangerDouble :public SizeChanger
{
public:
	SizeChangerDouble();
	virtual ~SizeChangerDouble() {};

private:
	static bool m_isRegister;
};
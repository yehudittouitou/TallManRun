#pragma once
#include "SizeChanger.h"
class SizeChangerLess :public SizeChanger
{
public:
	SizeChangerLess();
	virtual ~SizeChangerLess() {};
	
private:
	static bool m_isRegister;
};
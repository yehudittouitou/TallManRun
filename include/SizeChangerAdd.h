#pragma once
#include "SizeChanger.h"
class SizeChangerAdd :public SizeChanger
{
public:
	SizeChangerAdd();
	virtual ~SizeChangerAdd() {};

private:
	static bool m_isRegister;

};
#include "SizeChangerDouble.h"

bool SizeChangerDouble::m_isRegister = Factory::registerit(O_SIZECHANGERDBL, []()-> std::unique_ptr<RoadObject> {return std::make_unique<SizeChangerDouble>(); });

SizeChangerDouble::SizeChangerDouble()
	:SizeChanger('X', (std::rand() % 4)+2, ADDSIZE)
{
	m_num *= 10;
}


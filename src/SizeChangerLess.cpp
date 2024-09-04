#include "SizeChangerLess.h"

bool SizeChangerLess::m_isRegister = Factory::registerit(O_SIZECHANGERLESS, []()-> std::unique_ptr<RoadObject> {return std::make_unique<SizeChangerLess>(); });

SizeChangerLess::SizeChangerLess()
	:SizeChanger('-', (((std::rand() % 60)+10) / 10) * 10, LESSSIZE)
{
	m_num *= -1;
}


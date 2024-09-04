#include "SizeChangerDivide.h"
bool SizeChangerDivide::m_isRegister = Factory::registerit(O_SIZECHANGERDIV, []()-> std::unique_ptr<RoadObject> {return std::make_unique<SizeChangerDivide>(); });

SizeChangerDivide::SizeChangerDivide()
	:SizeChanger('%', (std::rand() % 4) + 2,LESSSIZE)
{
	m_num *= -10;
}

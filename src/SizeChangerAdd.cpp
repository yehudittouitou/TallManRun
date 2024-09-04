#include "SizeChangerAdd.h"
bool SizeChangerAdd::m_isRegister = Factory::registerit(O_SIZECHANGERADD, []()-> std::unique_ptr<RoadObject> {return std::make_unique<SizeChangerAdd>(); });

SizeChangerAdd::SizeChangerAdd()
	:SizeChanger('+', (((std::rand() % 60) + 10) / 10) * 10, ADDSIZE)
{
}


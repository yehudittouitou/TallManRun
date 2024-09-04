#include "Coin.h"
bool Coin::m_isRegister = Factory::registerit(O_COIN, []()-> std::unique_ptr<RoadObject> {return std::make_unique<Coin>(); });
//--------------------------------------------------------------------------------------------------------------------------------
Coin::Coin()
	:RoadObject(COIN, { 45,15 }, { float(0.01),float(0.01) }, { 6,1 }, { 6,1 })
{
}
//----------------------------------------
Coin::~Coin()
{
}














#pragma once
#include "Shoot.h"
#include "Factory.h"
class Spaceship : public RoadObject
{
public:
	Spaceship();
	virtual ~Spaceship();
	virtual void move()override;
	virtual void drawObject()override;
	virtual bool isFinish()const override;
	RoadObject& getShoot();
	void createShoot();
	virtual bool isColideWithPlayer(Player& player, const float& pos)override;
private:
	static bool m_isRegister;
	std::unique_ptr<RoadObject> m_shootBullet =nullptr;  // shoot ball

};


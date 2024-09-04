#pragma once
#include "ResourceManeger.h"
using namespace sf;
class Animation
{
public:
	Animation(Sprite& pic,const Vector2i& numOfIndexes, const float &speed=0.1);
	~Animation();
	void setRect();
	void updateIndexes();
	bool IsDone()const;
	void changeAnimation(const Vector2i& numOfIndexes);
private:
	float m_speed;                    // the speed of the picture exchange
	Clock m_clock;                    // a clock that checks if its time to replace a cut
	Sprite& m_picture;                // the picture
	Vector2i m_NumOfIndexes;          // num of cuts
	Vector2i m_curentIndex ={ 0,0 };  // the curent indexes of picture's cut
	IntRect m_rect = { 0,0,0,0 }; // save the width, length, x, and y - of the cuts
};

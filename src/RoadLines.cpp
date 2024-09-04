#include "RoadLines.h"
RoadLines::RoadLines()
	:Object(LINES,{0,0},{1350,950})
{
}

RoadLines::~RoadLines()
{
}
//---------------------------------
void RoadLines::moveLines()
{
	// the lines move up to a certain position and then back to the starting position 
	if (m_picture[m_curIndex].getPosition().y > 105.5)
		m_picture[m_curIndex].setPosition({ 0,0 });
	else
		m_picture[m_curIndex].move({ 0,1 });

}
//--------------------------------------------------
#include "Animation.h"
Animation::Animation(Sprite& pic, const Vector2i& numOfIndexes,const float & speed)
	:m_picture(pic),m_NumOfIndexes(numOfIndexes),m_speed(speed)
{
	m_rect.height = m_picture.getTextureRect().height; 
	m_rect.width = m_picture.getTextureRect().width;
}
//------------------------------
Animation::~Animation()
{
}
//----------------------------------
void Animation::setRect()
{
	if (m_clock.getElapsedTime().asSeconds() >= m_speed)
	{
		// Updates the start location of the cut
		m_rect.left= m_curentIndex.x*m_rect.width;
		m_rect.top= m_curentIndex.y * m_rect.height;

		// cut the picture
		m_picture.setTextureRect(m_rect);

		// restart the clock
		m_clock.restart();

		//updates the indexes
		updateIndexes();
	}	
}
//-------------------------------------------------
void Animation::updateIndexes()
{
	// move to the next picture
	m_curentIndex.x++;                        

	// if he gets to the end of the line
	if (m_curentIndex.x >= m_NumOfIndexes.x)   
	{
		// backs to the beginig of the line
		m_curentIndex.x = 0; 
		// move to the next line
		m_curentIndex.y++;                    
	}

	// if he gets to the end of the whole lines
	if (m_curentIndex.y >= m_NumOfIndexes.y)  
		// backs to the beginig of the picture
		m_curentIndex.y = 0;                  
}
//------------------------------------------------------------------------------
bool Animation::IsDone()const
{
	//check if he get to the final rect of the picture
	return (((m_NumOfIndexes.x - 1) == m_curentIndex.x) && ((m_NumOfIndexes.y - 1) == m_curentIndex.y));
}
//---------------------------------------------------------------------------------------
void Animation::changeAnimation(const Vector2i& numOfIndexes)
{
	//give the animation new indexes in order to see more cuts
	m_NumOfIndexes = numOfIndexes;
}


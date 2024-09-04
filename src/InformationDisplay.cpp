#include "InformationDisplay.h"
InformationDisplay::InformationDisplay()
{
	////-------------------------------Boat---------------------------------------
	m_boatPic.setTexture(ResourceManeger::getResourceManeger().getPic(BOAT));
	m_boatPic.scale({ 100 / m_boatPic.getLocalBounds().width,70 / m_boatPic.getLocalBounds().height });
	m_boatPic.setPosition({ 500,0 });
	////-------------------------------Hearts-------------------------------------
	m_heartPic.setTexture(ResourceManeger::getResourceManeger().getPic(HEARTINFO));
	////-------------------------------Coins---------------------------------------
	m_coinPic.setTexture(ResourceManeger::getResourceManeger().getPic(COININFO));
	m_coinPic.setPosition({ 50,0 });
	m_coinNumText.setFont(ResourceManeger::getResourceManeger().getFont(FONT1));
	m_coinNumText.setPosition({ 150,20 });
	////----------------------------------------------------------------------------
	updateInformation(0, NUM_OF_SHOW_HERAT, false);
}
//--------------------------------------------------------------------
InformationDisplay::~InformationDisplay()
{
}
//-------------------------------------------------------------
void InformationDisplay::draw()
{
	//draw coin pic
	ResourceManeger::getResourceManeger().getWindow().draw(m_coinPic); 
	//draw coin text
	ResourceManeger::getResourceManeger().getWindow().draw(m_coinNumText);
	// draw hearts                     
	for (int i = 0; i < NUM_OF_SHOW_HERAT; i++)
	{
		// draw red heart
		if (i < m_numOfLives)
			m_heartPic.setTextureRect(sf::IntRect(0,0,80,67));
		// draw gray heart
		else
			m_heartPic.setTextureRect(sf::IntRect(80, 0, 80, 67));
		// calculate position
		m_heartPic.setPosition({ m_firstHeartPos+(i*90),10 });
		// draw heart
		ResourceManeger::getResourceManeger().getWindow().draw(m_heartPic); 
	}
	//draw boat pic
	if(m_needToDrawBoat)                                                     
 		ResourceManeger::getResourceManeger().getWindow().draw(m_boatPic);    
}
//---------------------------------------------------------------
void InformationDisplay::updateInformation(const int& numofCoin, const int& lives, const bool& isHaveBoat)
{
	//update num of lives
	m_numOfLives = lives;
	//update num of coin text
	m_coinNumText.setString(std::to_string(numofCoin));
	//update if need to draw boat or not
	m_needToDrawBoat = isHaveBoat;
}
//--------------------------------------------------------------




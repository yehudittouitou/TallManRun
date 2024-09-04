#include "ResourceManeger.h"

ResourceManeger::ResourceManeger() 
{
	// create window
	m_window.create(sf::VideoMode(WIDTHOFBOARD,LENGHOFBOARD), "Tall Man Ran");
	m_window.setFramerateLimit(110);
	m_window.setPosition({ 200,0 });
	loadTexture();
	loadFont();
	loadSound();
}
//-------------------------------------------------------
//טעינת תמונןת
void ResourceManeger::loadTexture()
{
	std::vector <sf::Texture> pic(NUMOFPIC);

	if (!pic[WELCOME].loadFromFile("backgroundOpen.png"))
		std::cout << "can not open the picture file";

	if (!pic[PLAYBUTTON].loadFromFile("playButton.png"))
		std::cout << "can not open the picture file";

	if (!pic[EXITBUTTON].loadFromFile("exitButton.png"))
		std::cout << "can not open the picture file";

	if (!pic[BACKGROUNDLEVELS].loadFromFile("backgroundLevels.jpg"))
		std::cout << "can not open the picture file";

	if (!pic[SKY].loadFromFile("sky.png"))
		std::cout << "can not open the picture file";
	
	if (!pic[POOL].loadFromFile("pool.png"))
		std::cout << "can not open the picture file";

	if (!pic[MAGNET].loadFromFile("magnet.png"))
		std::cout << "can not open the picture file";

	if (!pic[HEART].loadFromFile("heart.png"))
		std::cout << "can not open the picture file";

	if (!pic[LINES].loadFromFile("lines.png"))
		std::cout << "can not open the picture file";

	if (!pic[FENCE].loadFromFile("fance.png"))
		std::cout << "can not open the picture file";

	if (!pic[CLOUD].loadFromFile("cloud.png"))
		std::cout << "can not open the picture file";

	if (!pic[BOMB].loadFromFile("bomb.png"))
		std::cout << "can not open the picture file";

	if (!pic[BOAT].loadFromFile("boat.png"))
		std::cout << "can not open the picture file";

	if (!pic[HELPBUTTON].loadFromFile("helpButton.png"))
		std::cout << "can not open the picture file";

	if (!pic[GOBACKBUTTON].loadFromFile("GoBackButton.png"))
		std::cout << "can not open the picture file";
	
	if (!pic[SPACESHIP].loadFromFile("spaceShip.png"))
		std::cout << "can not open the picture file";

	if (!pic[COIN].loadFromFile("coin.png"))
		std::cout << "can not open the picture file";

	if (!pic[SUPERPOWER].loadFromFile("superpower.png"))
		std::cout << "can not open the picture file";

	if (!pic[LESSSIZE].loadFromFile("lessSize.png"))
		std::cout << "can not open the picture file";

	if (!pic[ADDSIZE].loadFromFile("addSize.png"))
		std::cout << "can not open the picture file";

	if (!pic[COININFO].loadFromFile("coinInfo.png"))
		std::cout << "can not open the picture file";

	if (!pic[HEARTINFO].loadFromFile("heartInfo.png"))
		std::cout << "can not open the picture file";

	if (!pic[HEART].loadFromFile("heart.png"))
		std::cout << "can not open the picture file";

	if (!pic[PLAYERJUMP].loadFromFile("playerJump.png"))
		std::cout << "can not open the picture file";

	if (!pic[BUTTON].loadFromFile("button.png"))
		std::cout << "can not open the picture file";

	if (!pic[PLAYER0].loadFromFile("player0.png"))
		std::cout << "can not open the picture file";

	if (!pic[PLAYER1].loadFromFile("player1.png"))
		std::cout << "can not open the picture file";

	if (!pic[PLAYER2].loadFromFile("player2.png"))
		std::cout << "can not open the picture file";

	if (!pic[PLAYER3].loadFromFile("player3.png"))
		std::cout << "can not open the picture file";

	if (!pic[PLAYER4].loadFromFile("player4.png"))
		std::cout << "can not open the picture file";

	if (!pic[PLAYER5].loadFromFile("player5.png"))
		std::cout << "can not open the picture file";

	if (!pic[PLAYER6].loadFromFile("player6.png"))
		std::cout << "can not open the picture file";

	if (!pic[PLAYER7].loadFromFile("player7.png"))
		std::cout << "can not open the picture file";

	if (!pic[PLAYER8].loadFromFile("player8.png"))
		std::cout << "can not open the picture file";

	if (!pic[PLAYER9].loadFromFile("player9.png"))
		std::cout << "can not open the picture file";

	if (!pic[FAILPIC].loadFromFile("fail.png"))
		std::cout << "can not open the picture file";

	if (!pic[SIT].loadFromFile("sitOnBoat.png"))
		std::cout << "can not open the picture file";

	if (!pic[INPOOL].loadFromFile("inPool.png"))
		std::cout << "can not open the picture file";

	if (!pic[FINISH].loadFromFile("finish.png"))
		std::cout << "can not open the picture file";
	
	if (!pic[SUPERPOWERPLAYER].loadFromFile("superpowerPlayer.png"))
		std::cout << "can not open the picture file";

	if(!pic[MAGNETPLAYER].loadFromFile("magnetPlayer.png"))
		std::cout << "can not open the picture file";

	if (!pic[INSTRUCTION].loadFromFile("instruction.png"))
		std::cout << "can not open the picture file";

	if(!pic[WELCOMEBOY].loadFromFile("welcomeBoy.png"))
		std::cout << "can not open the picture file";
	

	
	m_picture = pic;
}
//------------------------------------------------
sf::Texture& ResourceManeger::getPic(const int& Pic)
{
	return m_picture[Pic];
}
//----------------------------------
//טעינת פונטים
void ResourceManeger::loadFont()
{
	std::vector<sf::Font> fonts(NUMOFFONTS);

	if (!fonts[FONT0].loadFromFile("ALGER.ttf"))
		std::cout << "Can not load font file";

	if (!fonts[FONT1].loadFromFile("BRLNSR.ttf"))
		std::cout << "Can not load font file";

	m_font = fonts;
}
//-------------------------------
//טעינת סאונדים
void ResourceManeger::loadSound()
{
	std::vector<sf::SoundBuffer> sounds(NUMOFSOUNDS);
	if (!sounds[COINSOUND].loadFromFile("coin.ogg"))
		std::cout << "Can not load sound file";
	if (!sounds[BOATSOUND].loadFromFile("boatsound.ogg"))
		std::cout << "Can not load sound file";
	if (!sounds[CHANGESIZESOUND].loadFromFile("changesizesound.ogg "))
		std::cout << "Can not load sound file";
	if (!sounds[HEARTSOUND].loadFromFile("heartsound.ogg"))
		std::cout << "Can not load sound file";
	if (!sounds[BOMBSOUND].loadFromFile("bombsound.ogg"))
		std::cout << "Can not load sound file";
	if (!sounds[LESSLIVESOUND].loadFromFile("lesslive.ogg"))
		std::cout << "Can not load sound file";
	if (!sounds[WINSOUND].loadFromFile("winsound.ogg"))
		std::cout << "Can not load sound file";
	if (!sounds[FAILSOUND].loadFromFile("fail.ogg"))
		std::cout << "Can not load sound file";
	if (!sounds[BACKGROUNDMELODY].loadFromFile("BackgroundMelody.ogg"))
		std::cout << "Can not load sound file";
	if (!sounds[RUNINGMELODY].loadFromFile("runingsound.ogg"))
		std::cout << "Can not load sound file";
	if (!sounds[POOLSOUND].loadFromFile("poolSound.ogg"))
		std::cout << "Can not load sound file";
	if (!sounds[TAKEOBJECT].loadFromFile("takeobj.ogg"))
		std::cout << "Can not load sound file";

	
	m_Sound = sounds;
}
//-------------------------------------
sf::Font& ResourceManeger::getFont(const int& text)
{
	return m_font[text];
}
//----------------------------------------
sf::RenderWindow& ResourceManeger:: getWindow()
{
	return m_window;
}
//-----------------------------
sf::SoundBuffer& ResourceManeger::getSound(const int& sound)
{
	return m_Sound[sound];
}
//------------------------------------------------------------------
void ResourceManeger::playCollisionSound(const int& whichSound)
{
	//play sound
	m_sound.setBuffer(ResourceManeger::getResourceManeger().getSound(whichSound));
	m_sound.play();
}
//-------------------------------------------------
void ResourceManeger::playBackGroundSound(const int& whichSound)
{
	//play music in loop
	m_BackGroundSound.setBuffer(ResourceManeger::getResourceManeger().getSound(whichSound));
	m_BackGroundSound.setVolume(20);
	m_BackGroundSound.play();
	m_BackGroundSound.setLoop(true);
}
//-------------------------------------------------------------------------
void ResourceManeger::stopBackGroundSound()
{
	//stop music
	m_BackGroundSound.stop();
}


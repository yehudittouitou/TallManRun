#include "Game.h"

//---------------------------------------
Game::Game()
    :m_menu(*this), m_startButton(BUTTON, { 475,740 }, { 400, 110 }),
    m_boy(WELCOMEBOY, { 860,100 }, { 2086,750 }, 1, { 4,1 })
    , m_textButton("START", FONT1, sf::Color::White, sf::Color::Black, { 590,755 },55,2)
    , m_textLevel("LEVEL 1", FONT1, sf::Color::Black, sf::Color::Black, { 430,290 },150)
    , m_textRecord("Record: " + std::to_string(m_Record), FONT1, sf::Color::Black, sf::Color::Black, { 570,500 },55)
{
    //backgroung picture
    m_welcomeBackground.setTexture(ResourceManeger::getResourceManeger().getPic(WELCOME));
    //backgroung music
    m_background.setTexture(ResourceManeger::getResourceManeger().getPic(BACKGROUNDLEVELS));
    //boy animation
    m_boyAnima = std::make_unique<Animation>(m_boy.getPic(), Vector2i{ 4,1 });
  
}
//----------------------------------
Game::~Game()
{

}
//-------------------------------
void Game::runOnMenu()
{
    // play music
    ResourceManeger::getResourceManeger().playBackGroundSound(BACKGROUNDMELODY);
    
    while (ResourceManeger::getResourceManeger().getWindow().isOpen())
    {
        // draw welcome screen (with menu)
        drawWelcomeScreen();
       // run on menu
        m_menu.run();
    }
}
//----------------------------------------------
void Game::drawWelcomeScreen()
{
    ResourceManeger::getResourceManeger().getWindow().clear();
    // draw background
    ResourceManeger::getResourceManeger().getWindow().draw(m_welcomeBackground);
    // draw menu
    m_menu.drawMenu();
    //draw waving boy
    m_boyAnima->setRect();
    m_boy.drawObject();
    //show all screen
    ResourceManeger::getResourceManeger().getWindow().display();
}
//---------------------------------------------
void Game::drawGame()
{

    ResourceManeger::getResourceManeger().getWindow().clear();

    // draw background
    ResourceManeger::getResourceManeger().getWindow().draw(m_background);

    // draw button
    m_startButton.drawObject();
    m_textButton.drawText();

    // draw texts
    m_textLevel.setString("LEVEL " + std::to_string(m_numOfLevel));
    m_textLevel.drawText();
    m_textRecord.setString("Record: " + std::to_string(m_Record));
    m_textRecord.drawText();

    ResourceManeger::getResourceManeger().getWindow().display();
}

//------------------------------------------------------------------
void Game::startGame()
{

    while(ResourceManeger::getResourceManeger().getWindow().isOpen())
    {
       
        // draw
        drawGame();
        //catch event
        auto event = sf::Event{};
        if (ResourceManeger::getResourceManeger().getWindow().waitEvent(event))
        {
            switch (event.type)
            {

            case sf::Event::Closed: exit();
            case sf::Event::MouseButtonReleased:
            {
                // location of click
                sf::Vector2f location = ResourceManeger::getResourceManeger().getWindow().mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
                // if click on button
                if (m_startButton.getPic().getGlobalBounds().contains(location))
                {
                    //stop music
                    ResourceManeger::getResourceManeger().stopBackGroundSound();
                    //if the game over
                    if (startLevel())
                    {
                        runOnMenu();
                        return;
                    }
                    ResourceManeger::getResourceManeger().playBackGroundSound(BACKGROUNDMELODY);
                }   
            }
            case sf::Event::MouseMoved:
            {
                //location of mouse
                sf::Vector2f location = ResourceManeger::getResourceManeger().getWindow().mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
                // if he touch button 
                if (m_startButton.getPic().getGlobalBounds().contains(location))
                {
                    //change color 
                    m_startButton.changeButtonColor({ 192,192,192,255 });
                }
                else
                   m_startButton.changeButtonColor(sf::Color::White);
            }

            }
        }
    }
}
//-------------------------------------------------------
bool Game::startLevel()
{
    //build level
    m_level = std::make_unique<Level>(m_numOfLevel);

    //play level sound
    ResourceManeger::getResourceManeger().playBackGroundSound(RUNINGMELODY);

    //run level
    if (m_level->run(m_Record))
    {
        //if he won- move to the next level
        m_numOfLevel++;

        //if the levels are over - back to level 1
        if (m_numOfLevel > NUMOFLEVELS)
        {
            m_numOfLevel = 1;
            return true;
        }
    }
    //if he lose
    return false;
}
//---------------------------------------------------------------------------


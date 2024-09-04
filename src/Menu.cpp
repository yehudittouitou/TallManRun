#include "Menu.h"
#include "Game.h"
Menu::Menu(Game& game)
{
    //build menu
    //each menu option includes button and command
    m_options.emplace_back(option(Button(PLAYBUTTON, { (WIDTHOFBOARD / 6) ,(LENGHOFBOARD / 2) - 200 }, { 400,110 }), make_unique <NewGame>(game)));
    m_options.emplace_back(option(Button(HELPBUTTON, { (WIDTHOFBOARD / 6) ,(LENGHOFBOARD / 2) - 50 }, { 400,110 }), make_unique <Help>()));
    m_options.emplace_back(option ( Button(EXITBUTTON, { (WIDTHOFBOARD / 6), (LENGHOFBOARD / 2) + 100 }, { 400,110 }), make_unique < Exit>(game)));
}
//------------------------------------------------------------------------------
Menu::~Menu()
{
}
//----------------------------------------------------------------------
void Menu::drawMenu()
{
    // draw buttons 
    for (int i = 0; i < m_options.size(); i++)
    {
        m_options[i].first.drawObject();
    }
}
//--------------------------------------------------
Activation Menu::findButton(const sf::Vector2f& location) 
{
    // run on the buttons and cheak if one of them contain the location
    for (int i = 0; i < m_options.size(); i++)
    {
        if (m_options[i].first.getPic().getGlobalBounds().contains(location))
            // return the action type
            return Activation(i);
    }
    return NOACTIVATION;
}
//---------------------------
void Menu::deleteColors()
{
    for (int i = 0; i < m_options.size(); i++)
    {
        m_options[i].first.changeButtonColor(sf::Color::White);
    }
}
//------------------------------------------------
//ריצה על התפריט
void Menu::run()
{

    auto event = sf::Event{};
    if (ResourceManeger::getResourceManeger().getWindow().pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            ResourceManeger::getResourceManeger().getWindow().close();
            exit(EXIT_SUCCESS);
        case sf::Event::MouseButtonReleased:
        {
            // mouse click location
            sf::Vector2f location =  ResourceManeger::getResourceManeger().getWindow().mapPixelToCoords (sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
            // look for button
            Activation type = findButton(location);
            // execute the command
            if(type!=NOACTIVATION)
                m_options[type].second->execute();
          
        }
        case sf::Event::MouseMoved:
        {
            sf::Vector2f location = ResourceManeger::getResourceManeger().getWindow().mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
            Activation button = findButton(location);
            if (button == NOACTIVATION)
                deleteColors();
            else
                m_options[button].first.changeButtonColor({ 192,192,192,255 });//שינוי צבע הכפתור
        }
        }
    }
}
//------------------------------------------------------------



#include "Help.h"

Help::Help()
    :m_goBackButton(GOBACKBUTTON, { 30,800 }, { 110,110})//כפתור
{
    //instruction picture
    m_instructionPic.setTexture(ResourceManeger::getResourceManeger().getPic(INSTRUCTION));
}
//--------------------------------------------------
Help::~Help() {}
//--------------------------------------------------
void Help::execute()
{
    while (ResourceManeger::getResourceManeger().getWindow().isOpen())
    {
        // draw screen
        draw();
        //catch event
        auto event = sf::Event{};
        if (ResourceManeger::getResourceManeger().getWindow().waitEvent(event))
        {
            switch (event.type)
            {

            case sf::Event::Closed:
                ResourceManeger::getResourceManeger().getWindow().close();
                break;

            case sf::Event::MouseButtonReleased:
            {
                //location of click
                sf::Vector2f location = ResourceManeger::getResourceManeger().getWindow().mapPixelToCoords(
                    { event.mouseButton.x, event.mouseButton.y });
                //if click on button
                if (m_goBackButton.getPic().getGlobalBounds().contains(location)) 
                {
                    m_goBackButton.changeButtonColor(sf::Color::White);
                    return;
                }
            }
            case sf::Event::MouseMoved:
            {
                //location of mouse
                sf::Vector2f location = ResourceManeger::getResourceManeger().getWindow().mapPixelToCoords({ event.mouseMove.x, event.mouseMove.y });
                if (m_goBackButton.getPic().getGlobalBounds().contains(location))
                    m_goBackButton.changeButtonColor({ 192,192,192,255 });
                else
                    m_goBackButton.changeButtonColor(sf::Color::White);
            }

            }
        }
    }
}
//------------------------------------------
void Help::draw()
{
    ResourceManeger::getResourceManeger().getWindow().clear();
    // show instructions
    ResourceManeger::getResourceManeger().getWindow().draw(m_instructionPic);
    m_goBackButton.drawObject();
    ResourceManeger::getResourceManeger().getWindow().display();
}
//------------------------------------------------------------

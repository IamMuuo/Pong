#include "HUD.hpp"
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Time.hpp>

Hud::Hud(float x, float y)
{
    // sets the text position
    this->x = x;
    this->y = y;
    position.x = x;
    position.y = y;

    text.setPosition(position);
    text.setCharacterSize(20);
    text.setFillColor(sf::Color::Green);
}

void Hud::setText(const std::string &text)
{
    // sets the text 
    this->text.setString(text);
}

void Hud::setFont(sf::Font& font)
{
    text.setFont(font);
}

sf::Text& Hud::getHUD()
{
    // returns rendable text
    return text;
}

void Hud::scrollText(sf::Time dt)
{
    if(text.getPosition().x > 820)
    {
        text.setPosition(x,y);
    }
    else
    {
        text.setPosition(
            text.getPosition().x  + (speed * dt.asSeconds()),
            text.getPosition().y
        );
    }
}
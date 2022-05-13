#ifndef _HUD_
#define _HUD_

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
struct Hud 
{
    private:
        sf::Vector2f position;
        sf::Text text;
        float x, y, speed = 20;

    public:
        Hud(float x, float y);
        void setText(const std::string& text);
        sf::Text& getHUD(); // returns drawable text
        void setFont(sf::Font& font);    // sets the font
        void scrollText(sf::Time dt);  // scrolls text
        void setSize(const float& size)
        {
            text.setCharacterSize(size);
        }
};
#endif //_HUD_
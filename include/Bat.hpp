#ifndef _BAT_
#define _BAT_

// a struct to represent the bat

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
struct Bat 
{
    private:
        sf::Vector2f position;

        sf::RectangleShape shape;

    public:
        Bat(float x, float y);
        sf::RectangleShape getShape();
        
};
#endif /*_BAT_*/
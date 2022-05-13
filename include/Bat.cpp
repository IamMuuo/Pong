#include "Bat.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

// Constructor to instanciate the position of the ball initially
Bat::Bat(float x, float y)
{
    position.x = x;
    position.y = y;

    shape.setSize(sf::Vector2f(100,5));
    shape.setPosition(position);
}

sf::RectangleShape Bat::getShape()
{
    // returns the bat
    return shape;
}
#include "Ball.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>

Ball::Ball(float startX, float startY)
{
    position.x = startX;
    position.y = startY;

    shape.setPosition(position);
    shape.setRadius(10);
}

sf::CircleShape& Ball::getBall()
{
    return shape;
}
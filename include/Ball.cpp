#include "Ball.hpp"
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Time.hpp>
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

void Ball::update(const sf::Time &dt)
{
    position.x += m_directionX * speed * dt.asSeconds();
    position.y += m_directionY * speed * dt.asSeconds();
    shape.setPosition(position);
}

sf::Vector2f Ball::getPosition()
{
    return shape.getPosition();
}

sf::FloatRect Ball::getBounds()
{
    return shape.getGlobalBounds();
}

void Ball::reboundBatOrTop()
{
    m_directionY = -1 * m_directionY;
}

void Ball::reboundSides()
{
    m_directionX = -1 * m_directionX;
}

void Ball::reboundBottom()
{
    position.y = 0;
    position.x = 500;
    m_directionY = -m_directionY;
}

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
    // returns the drawable bat
    return shape;
}


void Bat::moveLeft()
{
    // set to move the bat to the left 
    if(position.x < 10)
        movingLeft = false;
    else  
        movingLeft = true;

}


void Bat::moveRight()
{
    // set to move the bat to the right
    if(position.x > 700)
        movingRight = false;
    else  
        movingRight = true;
}

void Bat::update(sf::Time dt)
{
    // does the actuall moving
    if(movingLeft)
        position.x -= speed * dt.asSeconds();

    if(movingRight)
        position.x += speed * dt.asSeconds();

    shape.setPosition(position);
}

void Bat::stopLeft()
{
    movingLeft =false;
}

void Bat::stopRight()
{
    movingRight=false;
}

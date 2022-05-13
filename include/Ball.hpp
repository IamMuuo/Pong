#ifndef _BALL_
#define _BALL_

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
struct Ball 
{
    private:
        sf::Vector2f position;
        sf::CircleShape shape;

        float speed = 1000.0f;

    public:
        Ball(float startX, float startY);
        sf::CircleShape& getBall();
};
#endif
#ifndef _BALL_
#define _BALL_

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>

struct Ball 
{
    private:
        sf::Vector2f position;
        sf::CircleShape shape; 


        // moving speeds
        float speed = 1000.0f;
        float m_directionX = 0.2f;
        float m_directionY = 0.2f;

    public:
        Ball(float startX, float startY);
        sf::CircleShape& getBall();
        void update(const sf::Time& dt);
        void moveBall();
        sf::Vector2f getPosition();
        sf::FloatRect getBounds();

        void reboundBatOrTop();
        void reboundSides();
        void reboundBottom();

};
#endif
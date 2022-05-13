#ifndef _BAT_
#define _BAT_

// a struct to represent the bat

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Vector2.hpp>
struct Bat 
{
    private:
        sf::Vector2f position;

        sf::RectangleShape shape;

        float speed = 1000.0f;

        bool movingRight = false;

        bool movingLeft = false;

    public:
        Bat(float x, float y);

        sf::RectangleShape getShape();

        void moveRight(); // mov the bat to the right
        
        void moveLeft(); // mov the bat to the left
        
        void update(sf::Time dt);   // updates the bat position

        void stopLeft();
        void stopRight();
};
#endif /*_BAT_*/
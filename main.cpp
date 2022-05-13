/*********************************************************
*   Filename: Pong.cpp
*   Author: Eric Muuo
*   Email:  hearteric57@gmail.com
*   
*
*   Contains the main entry point to the program
*********************************************************/
#include "include/Bat.hpp"
#include "include/HUD.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <cstdlib>
#include <iostream>

int main()
{
    // create a video mode object
    sf::VideoMode vm(800,600);

    sf::RenderWindow window(vm,"Pong",sf::Style::Close);

    Bat bat((800.0f/2.0f) - 50, 600 - 20);

    sf::Clock clock;

    sf::Event event;

    sf::Font font;
    font.loadFromFile("Assets/Font/font.otf");

    // hud
    Hud scoreText(0,0), helpText(400,0);
    scoreText.setFont(font);
    helpText.setFont(font);
    scoreText.setText("Score: 0");
    helpText.setText("This is the help text");
    scoreText.setSize(20);
    helpText.setSize(20);

    while(window.isOpen())
    {
        /*****************************************************
        *   Handle the user input
        *****************************************************/

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            // terminate the game
            window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            bat.moveLeft();
        }
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            bat.moveRight();
        }


        while (window.pollEvent(event)) {
            if(event.type == sf::Event::KeyReleased)
            {
                bat.stopLeft();
                bat.stopRight();
            }

            if(event.type == sf::Event::Closed )
            {
                window.close();
            }
        }
        /****************************************************
        *   Time
        ****************************************************/
        sf::Time dt = clock.restart();
        bat.update(dt);

        /****************************************************
        *   clear the window
        *****************************************************/
        window.clear();

        /****************************************************
        *   Draw game objects
        ****************************************************/
        
        window.draw(bat.getShape());
        window.draw(helpText.getHUD());
        window.draw(scoreText.getHUD());
        
        /****************************************************
        *   Display the objects onto the screen
        *****************************************************/
        helpText.scrollText(dt);

        window.display();

    }

    return EXIT_SUCCESS;

}
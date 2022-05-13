/*********************************************************
*   Filename: Pong.cpp
*   Author: Eric Muuo
*   Email:  hearteric57@gmail.com
*   
*
*   Contains the main entry point to the program
*********************************************************/
#include "include/Bat.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <cstdlib>

int main()
{
    // create a video mode object
    sf::VideoMode vm(1920,1080);

    sf::RenderWindow window(vm,"Pong",sf::Style::Fullscreen);

    Bat bat(1920.0f/2.0f, 1080 - 20);

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
        /****************************************************
        *   clear the window
        *****************************************************/
        window.clear();

        /****************************************************
        *   Draw game objects
        ****************************************************/
        
        window.draw(bat.getShape());
        /****************************************************
        *   Display the objects onto the screen
        *****************************************************/

        window.display();

    }

    return EXIT_SUCCESS;

}
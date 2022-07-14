/***********************************************************
*   file: Game.hpp
*   Author: Eric Muuo
*   Description Contains the came class 
***********************************************************/

#pragma once

#include "Ball.hpp"
#include "Bat.hpp"
#include "HUD.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/VideoMode.hpp>

struct Game
{
    private:
        sf::RenderWindow window;
        bool isRunning = false; // game paused?
        void update(const sf::Time& dt);  // update the game frame
        void render();  // render the game objects
        void processEvents();   // process the game events

        Bat bat;
        Ball ball;

        sf::Font gameFont;  // font to be used in the game
        Hud scoreText;
        Hud logText;
        Hud pauseText;

        int lives = 3;
        int score = 0;

    public:
        Game(); // initialize the window
        void run(); // keep the game running
};
#include "Game.hpp"
#include "HUD.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <bits/types/FILE.h>
#include <sstream>

Game::Game()
: window(sf::VideoMode(800,600),"Pong!",sf::Style::Titlebar|sf::Style::Close),
bat((800.0f/2.0f) - 50, 600 - 20),
ball((800.0f/2.0f),600.0f/2.0f),
scoreText(10, 10),
logText(300,10),
pauseText(100, 600.f / 2)
{
    window.setFramerateLimit(120);  // set 120 fps
    gameFont.loadFromFile("Assets/Font/font.otf");

    logText.setFont(gameFont);
    scoreText.setFont(gameFont);

    logText.setText("Keep the ball bouncing");
    scoreText.setText("Score: 0");

    pauseText.setFont(gameFont);
    pauseText.setText("Game Paused hit <Space> to play!\nHit K during gameplay to pause:)");
    pauseText.setSize(30);
}

void Game::render()
{
    if(isRunning){
    // draw the objects into the screen
    window.clear(); // clear the last frame
    window.draw(scoreText.getHUD());
    window.draw(logText.getHUD());
    window.draw(ball.getBall());
    window.draw(bat.getShape());
    }
    else
    {
        window.clear();
        window.draw(pauseText.getHUD());
        window.draw(logText.getHUD());
        window.draw(scoreText.getHUD());
    }

    // display the new frame
    window.display();
}


void Game::processEvents()
{
    // process inputs
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
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
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::K))
        isRunning = false;

    sf::Event event;

    while (window.pollEvent(event))
    {
        if(event.type == sf::Event::KeyReleased)
        {
            bat.stopRight();
            bat.stopLeft();
            
        }

        if(event.type == sf::Event::Closed)
        {
            window.close();
        }

        if(event.type == sf::Event::Resized)
            isRunning = false;
        
        }
}

void Game::update(const sf::Time& dt)
{
    if(isRunning)
    {
        bat.update(dt);
        ball.update(dt);

        if(ball.getPosition().y > window.getSize().y)
        {
            ball.reboundBottom();
            lives--;
        }
        if(ball.getPosition().y < 0)
        {
            ball.reboundBatOrTop();
        }
        
        // rebounding from sides
        if(ball.getPosition().x < 0 ||
            ball.getPosition().x + 10 > window.getSize().x)
        {
            ball.reboundSides();
        }
        
        // get the ball to rebound from bat
        if(ball.getBounds().intersects(bat.getShape().getGlobalBounds()))
        {
            ball.reboundBatOrTop();
            score++;
        }

        logText.scrollText(dt);

        if(lives > 0)
        {
            logText.setText("Great job");
        }
        else
        {
            logText.setText("You ran out of lives!\nBetter luck next time");
            std::stringstream ss; 
            ss << "You lost after scoring: " << score;
            pauseText.setText(ss.str());
            isRunning = false;
            score = 0;
            lives = 3;
        }

        std::stringstream ss;
        ss << "Score: " << score << " Lives: " << lives;
        scoreText.setText(ss.str()); 
    }
    else
    {
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            isRunning = true;
        }
    }
}

// call the game loop
void Game::run()
{

    sf::Clock clock;
    while (window.isOpen()) 
    {
        sf::Time dt = clock.restart();
        processEvents();
        update(dt);
        render(); 
    }
}

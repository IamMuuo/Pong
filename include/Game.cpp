#include "Game.hpp"
#include "HUD.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <sstream>

Game::Game()
: window(sf::VideoMode(800,600),"Pong!",sf::Style::Titlebar|sf::Style::Close),
bat((800.0f/2.0f) - 50, 600 - 20),
ball((800.0f/2.0f),600.0f/2.0f),
scoreText(10, 10),
logText(100,10)
{
    window.setFramerateLimit(120);  // set 120 fps
    gameFont.loadFromFile("Assets/Font/font.otf");

    logText.setFont(gameFont);
    scoreText.setFont(gameFont);

    logText.setText("Keep the ball bouncing");
    scoreText.setText("Score: 0");
}

void Game::render()
{
    // draw the objects into the screen
    window.clear(); // clear the last frame
    window.draw(scoreText.getHUD());
    window.draw(logText.getHUD());
    window.draw(ball.getBall());
    window.draw(bat.getShape());

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

        std::stringstream ss;
        ss << "Score: " << score << " Lives: " << lives;
        scoreText.setText(ss.str()); 
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
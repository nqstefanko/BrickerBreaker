#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Sprite.cpp"
#include "Point.cpp"
#include "Ball.cpp"
#include "Paddle.cpp"

#include <iostream>

void checkBallOutOfBounds(Ball & b, sf::RenderWindow & window)
{
    if(b.getX() + b.getRadius()*2 > window.getSize().x || b.getX() < 0)
    {
        b.setSpeed(b.getXSpeed()*-1, 0, true, false);//Reverse in X direction!
    }

    if(b.getY() + b.getRadius()*2 > window.getSize().y || b.getY() < 0)
    {
        b.setSpeed(0, b.getYSpeed()*-1, false, true);//Reverse in Y direction
    }
}

void doBasicsForBall(Ball & b, sf::RenderWindow & window)
{
    b.drawBall(window);
    b.moveBallInDirection();
    checkBallOutOfBounds(b, window);
}

int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setFramerateLimit(70);
    Ball b(20, 0, 0, 5, 5);
    Paddle p(150 ,20, 0,0,0,0);
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window

            if (event.type == sf::Event::Closed)
                window.close();
        }
        // clear the window with black color
        window.clear(sf::Color::Black);

        //checkIfKeysArePressed(p, window);

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            p.setSpeed(-10,0,true, false);
            p.drawPaddle(window);
            p.movePaddleInDirection();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            p.setSpeed(10,0,true, false);
            p.drawPaddle(window);
            p.movePaddleInDirection();
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            // sf::Vector2i position = sf::Mouse::getPosition();
            // std::cout << "BALLX: " << position.x << " BALLY: " << position.y << std::endl;
            // //std::cout << "BALLX: " << b.getX() << " BALLY: " << b.getY() << std::endl;
            // std::cout << "BALLCENTER: " << b.getCenter().first << " BALLCENTER2: " << b.getCenter().second << std::endl;
            // //std::cout << "PADDLEX: " << p.getX() << " PADDDLE: " << p.getY() << std::endl;            
        }

        p.drawPaddle(window);
        doBasicsForBall(b, window);

        window.display();
    }

    return 0;
}



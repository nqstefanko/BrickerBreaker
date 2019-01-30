#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Sprite.cpp"
#include "Point.cpp"
#include "Ball.cpp"
#include "Paddle.cpp"
#include "Brick.cpp"
#include "Brick.hpp"

#include <unistd.h>
#include <chrono>
#include <iostream>
#include <future>
typedef std::chrono::high_resolution_clock Clock;
auto timeToStart = std::chrono::system_clock::now();

sf::Text text;

void doBasicsForBall(Ball & b, sf::RenderWindow & window)
{
    b.drawBall(window);
    b.moveBallInDirection();
    checkBallOutOfBounds(b, window);
}

void setInvince() {
    std::this_thread::sleep_for(std::chrono::milliseconds(250));
}

void sendBallBackwards(Rect & r, Ball & b) {
    float leftCorner = 180-r.getAngleFromCenterToCorner();
    float rightCorner = r.getAngleFromCenterToCorner();
    double addToX= 0;
    double addToY= 0;

    if((r.getAngleFromCenterOfBall(b) < 20 || r.getAngleFromCenterOfBall(b)> 160) 
            && (std::abs(b.getXSpeed() + b.getYSpeed()) > 10) && 
                    (std::abs(b.getXSpeed() + b.getYSpeed()) < 14)) {
        addToX=-(float) rand()/RAND_MAX;
        addToY=-(float) rand()/RAND_MAX;
    } else {
        addToX=((float) rand()/RAND_MAX)/10;
        addToY=((float) rand()/RAND_MAX)/5;
    }
    if(std::abs(r.getAngleFromCenterOfBall(b)) > rightCorner || std::abs(r.getAngleFromCenterOfBall(b)) < leftCorner ) {

        b.setSpeed(b.getXSpeed()*-1+addToX, b.getYSpeed());
    } else {
        b.setSpeed(b.getXSpeed(), b.getYSpeed()*-1 + addToY);
    }
    b.canBeAffected = false;
}

void checkBallOutOfBounds(Ball & b, sf::RenderWindow & window)
{
    if(b.getX() + b.getRadius()*2 > window.getSize().x || b.getX() < 0)
    {
        b.setSpeed(b.getXSpeed()*-1, 0, true, false);//Reverse in X direction!
    }

    if( b.getY() < 0)
    {
        b.setSpeed(0, b.getYSpeed()*-1, false, true);//Reverse in Y direction
    }
   if(b.getY() + b.getRadius()*2 > window.getSize().y) {
        text.setString("YOU LOSE");
        text.setColor(sf::Color::Red);
        window.draw(text);
        window.display();
        usleep(3000000);
        window.close();
   }
}


int main()
{
    // create the window
    int colllidedCount = 0;
    auto prev = Clock::now();
    sf::Font font;
    sf::RenderWindow window(sf::VideoMode(1600, 900), "My window");

    font.loadFromFile("FontFile.ttf");
    text.setFont(font); // font is a sf::Font
    text.setCharacterSize(150); // in pixels, not points!
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);
    text.setColor(sf::Color::White);
    text.setPosition(window.getSize().x/2, window.getSize().y/2);


    window.setFramerateLimit(70);
    Ball b(30, window.getSize().x/2, window.getSize().y/2, 6, 6);

    if( ((float)rand()/RAND_MAX) > .5) {
        b.setSpeed(b.getXSpeed()*-1, b.getYSpeed());
    }

    Paddle p(150 ,20, window.getSize().x/2, window.getSize().y/1.25,0,0);
    std::vector<std::vector<Brick>> allBricks(3);
    
    for(int i = 0; i < 3;++i) {
        std::vector<Brick> tempVector;
        for(int j = 0; j < 8;++j) {
            Brick temp(window.getSize().x/10, window.getSize().y/30, 
                    window.getSize().x/10+(10*j)+window.getSize().x/10*j,
                     window.getSize().y/30+(10*i)+window.getSize().y/30*i);
            tempVector.push_back(temp);
        }   
        allBricks[i] = (tempVector);
    }

    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        // clear the window with black color
        window.clear(sf::Color::Black);

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

        if(p.checkIfBallWithinBounds(b)) {
            if(std::chrono::duration_cast<std::chrono::nanoseconds>(Clock::now()-prev).count() > 20000000) {
                sendBallBackwards(p, b);
                prev = Clock::now();
            }
        }

        std::chrono::duration<double> diff = std::chrono::system_clock::now()-timeToStart;
        if(diff.count() > .05){
            b.canBeAffected = true;
        }

        
        for(int i = 0; i < 3;++i) {
            for(int j = 0; j < 8;++j) {
                if(allBricks[i][j].checkIfBallWithinBounds(b)) {
                    if(allBricks[i][j].collided == true) {
                    } else {
                        ++colllidedCount;
                        sendBallBackwards(allBricks[i][j], b);
                        allBricks[i][j].collided=true;
                    }
                } else {
                    if(allBricks[i][j].collided == false) {
                        allBricks[i][j].drawBrick(window);
                    }
                }

            }   
        }
        if(colllidedCount == 24) {
            text.setString("YOU WIN");
            window.draw(text);
            window.display();
            usleep(3000000);
            window.close();
        }
        p.drawPaddle(window);
        doBasicsForBall(b, window);

        window.display();
    }

    return 0;
}



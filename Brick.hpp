#ifndef BRICK_H
#define BRICK_H

#include "Rect.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <utility>

class Brick: public Rect
{
	sf::Texture brickTexture;

public:
	bool collided;

	Brick(int w, int h, float x, float y);
	
	Brick();

	void drawBrick(sf::RenderWindow & win);

	void loadTexture(std::string shapeTexture);

};

#endif


























// #ifndef BALL_H
// #define BALL_H
// #include <SFML/Graphics.hpp>
// #include <SFML/Window.hpp>
// #include <string>

// class Ball
// {
// private:
// 	float xPos;
// 	float yPos;

// 	float xSpeed;
// 	float ySpeed;

// 	int radius;//New

// 	sf::CircleShape ballShape;//New
// 	sf::Texture ballTexture;


// public:
// 	Ball(int r); //new

// 	float getX();

// 	float getY();

// 	float getXSpeed();

// 	float getYSpeed();

// 	int getRadius(); //new

// 	void drawBall(sf::RenderWindow & win);

// 	void setPos(int x, int y);

// 	void loadTexture(std::string shapeTexture);

// 	void moveBallInDirection();

// 	void setSpeed(float newX, float newY, bool changeX, bool changeY);

// };

// #endif
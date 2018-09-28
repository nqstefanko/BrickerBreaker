#ifndef BALL_H
#define BALL_H

#include "Sprite.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <utility>

class Ball : public Sprite
{
private:
	int radius;//New
	sf::CircleShape ballShape;//New
	sf::Texture ballTexture;

public:
	Ball(int r, float x, float y, float xSpeed, float ySpeed); //new

	int getRadius(); //new

	void drawBall(sf::RenderWindow & win);

	void setPosBall(int x, int y);

	std::pair<float, float> getCenter();

	void loadTexture(std::string shapeTexture);

	void moveBallInDirection();

	float getDistanceFromCenter(Point p);

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
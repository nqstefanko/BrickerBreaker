#ifndef SPRITE_H
#define SPRITE_H
#include "Point.hpp"
#include "Timer.hpp"



class Sprite
{
public:

	Point position;

	float xSpeed;
	float ySpeed;
	bool canBeAffected = true;
    //Timer invincibilityTimer;


	void setPosition(float x, float y);

	float getX();

	float getY();

	void setSpeed(float newX, float newY, bool changeX, bool changeY);

	float getXSpeed();

	float getYSpeed();

	void setInvincibility();
	
	void setIt(bool yah);

};

#endif

































	// void moveShapeInDirection();

	// void setSpeed(float newX, float newY, bool changeX, bool changeY);

	// void drawShape(sf::RenderWindow & win);

	// void loadTexture(std::string shapeTexture);
#include "Sprite.hpp"
#include "Timer.cpp"

#include <iostream>
#include <chrono>
#include <iostream>
#include <future>
#include <thread>


void Sprite::setPosition(float x, float y) {
	position.setX(x);
	position.setY(y);
}

float Sprite::getX()
{
	return position.getX();
}

float Sprite::getY()
{
	return position.getY();
}

float Sprite::getXSpeed()
{
	return xSpeed;
}

float Sprite::getYSpeed()
{
	return ySpeed;
}

// void Sprite::setInvincibility() {
// 	canBeAffected = false;
// 	bool * s = &canBeAffected;
//     invincibilityTimer.start(chrono::milliseconds(100), [](bool * s){
//        	*s = true
//     });

//     this_thread::sleep_for(chrono::milliseconds(250));
//     invincibilityTimer.stop();	
//     canBeAffected  = true;
// }

void Sprite::setSpeed(float newX, float newY, bool changeX = true, bool changeY = true)
{
	if(canBeAffected) {
		if(changeX)
		{
			xSpeed = newX;
		}
		
		if(changeY)
		{
			ySpeed = newY;
		}
	}
}
































// void Sprite::moveShapeInDirection()
// {
// 	shape.move(xSpeed, ySpeed);
// 	xPos+=xSpeed;
// 	yPos+=ySpeed;
// }

// void Sprite::drawShape(sf::RenderWindow & win)
// {
// 	win.draw(shape);
// }

// void Sprite::setPos(int x, int y)
// {
// 	shape.setPosition(x, y);
// }

// void Sprite::loadTexture(std::string shapeTexture)
// {
// 	texture.loadFromFile(shapeTexture);
// 	shape.setTexture(&texture);
// }

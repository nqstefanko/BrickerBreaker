#include "Sprite.hpp"
#include <iostream>

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

void Sprite::setSpeed(float newX, float newY, bool changeX = true, bool changeY = true)
{
	if(changeX)
	{
		xSpeed = newX;
	}
	
	if(changeY)
	{
		ySpeed = newY;
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

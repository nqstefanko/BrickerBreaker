#include "Ball.hpp"
#include <iostream>
#include <utility>
#include <cmath>

Ball::Ball(int r, float x, float y, float xS, float yS)
{
	radius = r;
	ballShape.setRadius(r);
	
	setPosition(x, y);
	ballShape.setPosition(x, y);


	xSpeed = xS;
	ySpeed = yS;
	
	std::string textureString = "happyFace.png";
	loadTexture(textureString);
	std::cout << "Ball Contructor" <<std::endl;
}

void Ball::setPosBall(int x, int y) {
	setPosition(x, y);
	ballShape.setPosition(x, y);
}

int Ball::getRadius() { //new
	return radius;
}

void Ball::drawBall(sf::RenderWindow & win)
{
	win.draw(ballShape);
}

std::pair<float, float> Ball::getCenter()
{
	std::pair <float, float> p(position.getX() + radius,
								position.getY() + radius);
	return p;
}

void Ball::loadTexture(std::string shapeTexture)
{
	ballTexture.loadFromFile(shapeTexture);
	ballShape.setTexture(&ballTexture);
}

void Ball::moveBallInDirection()
{
	ballShape.move(xSpeed, ySpeed);

	position.setX(position.getX()+xSpeed);
	position.setY(position.getY()+ySpeed);
	//std::cout << yPos << std::endl;
	//ballShape.setOrigin(xPos + radius, yPos+radius);
}

float Ball::getDistanceFromCenter(Point p)
{
	return position.getDistanceBetweenPoints(p); //Distance Formula 
}
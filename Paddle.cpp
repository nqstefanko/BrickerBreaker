#include "Paddle.hpp"
#include "Rect.cpp"
#define PI 3.14159265

// #include <Vector2>

Paddle::Paddle(int w, int h, float x, float y, float xS, float yS) : Rect(w, h, x, y)
{
	xSpeed = xS;
	ySpeed = yS;
	
	std::string textureString = "rubber.jpg";
	loadTexture(textureString);
}

void Paddle::drawPaddle(sf::RenderWindow & win)
{
	win.draw(rectShape);
}

void Paddle::loadTexture(std::string shapeTexture)
{
	paddleTexture.loadFromFile(shapeTexture);
	rectShape.setTexture(&paddleTexture);
}

void Paddle::movePaddleInDirection()
{
	rectShape.move(xSpeed, ySpeed);
	position.setX(position.getX()+xSpeed);
	position.setY(position.getY()+ySpeed);
	//std::cout << xPos <<  " " << yPos << std::endl;	
}

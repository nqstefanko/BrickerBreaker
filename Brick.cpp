#include "Brick.hpp"
#include "Rect.hpp"



Brick::Brick(int w, int h, float x, float y) : Rect(w, h, x, y)
{
	collided = false;
	std::cout << " brick Contsuctor" << std::endl;
	std::string textureString = "brick.jpeg";
	loadTexture(textureString);
	rectShape.setOutlineThickness(4);
	rectShape.setOutlineColor(sf::Color(0, 0, 0));
}

Brick::Brick() : Rect(160, 30, 0, 0)
{
	std::string textureString = "brick.jpeg";
	loadTexture(textureString);
}

void Brick::drawBrick(sf::RenderWindow & win)
{

	std::string textureString = "brick.jpeg";
	loadTexture(textureString);
	win.draw(rectShape);
}

void Brick::loadTexture(std::string shapeTexture)
{
	brickTexture.loadFromFile(shapeTexture);
	rectShape.setTexture(&brickTexture);
}

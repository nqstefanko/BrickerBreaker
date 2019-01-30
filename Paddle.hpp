#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <utility>
#include <cmath>
#include "Rect.hpp"

class Paddle : public Rect
{
private:	
	//sf::RectangleShape paddleShape;//New
	sf::Texture paddleTexture;

public:
	Paddle(int w, int h, float x, float y, float xS, float xY); //new

	void drawPaddle(sf::RenderWindow & win);

	void loadTexture(std::string shapeTexture);

	void movePaddleInDirection();
};

#endif

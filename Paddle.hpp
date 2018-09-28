#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <utility>
#include <cmath>

class Paddle : public Sprite
{
private:
	int width;//New
	int height;//New
	
	sf::RectangleShape paddleShape;//New
	sf::Texture paddleTexture;

public:
	Paddle(int w, int h, float x, float y, float xS, float xY); //new

	int getWidth(); //new
	
	int getHeight();

	void drawPaddle(sf::RenderWindow & win);

	void setPosPaddle(int x, int y);

	void loadTexture(std::string shapeTexture);

	void movePaddleInDirection();

	bool checkIfBallWithinBounds(Ball & b);

	void CheckCollisionWithBall(Ball & b);
};

#endif

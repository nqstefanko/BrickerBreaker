#ifndef RECT_H
#define RECT_H

#include "Sprite.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
#include <utility>
#include <cmath>

class Rect : public Sprite
{
protected:
	int width;//New
	int height;//New
	
	sf::RectangleShape rectShape;//New

public:
	Rect(int w = 160, int h=30, float x=0, float y=0); //new
	
	//Rect(Rect & r); //new

	int getWidth(); //new
	
	int getHeight();

	void setPosRect(int x, int y);

	bool checkIfBallWithinBounds(Ball & b);

	void CheckCollisionWithBall(Ball & b);

	float getAngleFromCenterToCorner();
	
	std::pair<float, float> getCenterOfRect();

	float getAngleFromCenterOfBall(Ball & b);
};

#endif

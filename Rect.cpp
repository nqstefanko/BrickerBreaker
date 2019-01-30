#include "Rect.hpp"
#define PI 3.14159265

Rect::Rect(int w, int h, float x, float y)
{
	width  = w;
	height = h;

	sf::Vector2f widthAndHeight(w,h);
	rectShape.setSize(widthAndHeight);
	
	setPosRect(x, y);
}

int Rect::getWidth()
{
	return width;
}

int Rect::getHeight()
{
	return height;
}

void Rect::setPosRect(int x, int y)
{
	setPosition(x, y);
	rectShape.setPosition(x, y);
	sf::FloatRect r = rectShape.getLocalBounds();
}


bool Rect::checkIfBallWithinBounds(Ball & b)
{
	std::pair <float, float> ballCenter = b.getCenter();
	std::pair <float, float> rectCenter = getCenterOfRect();

	int circleDistanceX = std::abs(ballCenter.first - rectCenter.first);
	int circleDistanceY = std::abs(ballCenter.second - rectCenter.second);

    if (circleDistanceX > (width/2 + b.getRadius())) { return false; }
    if (circleDistanceY > (height/2 + b.getRadius())) { return false; }

    if (circleDistanceX <= (width/2)) { return true; } 
    if (circleDistanceY <= (height/2)) { return true; }

    int cornerDistance_sq = pow((circleDistanceX - width/2),2) +
                         pow((circleDistanceY - height/2),2);

    return (cornerDistance_sq <= (b.getRadius()^2));
}

std::pair<float, float> Rect::getCenterOfRect() {
	std::pair<float, float> p(position.getX()+width/2,
								position.getY()+height/2);
	return p;
}

float Rect::getAngleFromCenterToCorner() {
	std::pair <float, float> rectCenter = getCenterOfRect();
	float dx = position.getX() - rectCenter.first;
    // Minus to correct for coord re-mapping
    float dy = -(position.getY() - rectCenter.second);
    float result = atan2 (dy,dx) * 180 / PI;
    return result;
}

float Rect::getAngleFromCenterOfBall(Ball & b) {
	std::pair <float, float> ballCenter = b.getCenter();
	std::pair <float, float> rectCenter = getCenterOfRect();
	float dx = rectCenter.first-ballCenter.first;
    // Minus to correct for coord re-mapping
    float dy = -(rectCenter.second-ballCenter.second);
    float result = atan2 (dy,dx) * 180 / PI;
    return result;
}
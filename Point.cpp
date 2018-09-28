#include "Point.hpp"
#include <cmath>

Point::Point() {
	xPos = 0;
	yPos = 0;
}

Point::Point(float x, float y) {
	xPos = x;
	yPos = y;
}

float Point::getY() {
	return yPos;
}

float Point::getX() {
	return xPos;
}

void Point::setX(float x) {
	xPos = x;
}
void Point::setY(float y) {
	yPos = y;
}

void Point::addToCoordinate(float x, float y) {
	xPos+=x;
	yPos+=y;
}

float Point::getDistanceBetweenPoints(Point P) {

	return sqrt(  pow(xPos-P.getX(),2) + pow(yPos-P.getY(),2)  ); 
}
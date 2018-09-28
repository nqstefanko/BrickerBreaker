#ifndef POINT_H
#define POINT_H

class Point {
private:
	float xPos;
	float yPos;

public:
	Point(float x, float y);
	Point();
	float getX();
	float getY();
	void setX(float x);
	void setY(float y);
	void addToCoordinate(float x, float y);
	float getDistanceBetweenPoints(Point P);
};

#endif
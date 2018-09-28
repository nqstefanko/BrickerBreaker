#include "Paddle.hpp"
// #include <Vector2>

Paddle::Paddle(int w, int h, float x, float y, float xS, float yS)
{
	width  = w;
	height = h;

	sf::Vector2f widthAndHeight(w,h);
	paddleShape.setSize(widthAndHeight);
	
	setPosition(x, y);
	xSpeed = xS;
	ySpeed = yS;
	
	std::string textureString = "rubber.jpg";
	loadTexture(textureString);
}



int Paddle::getWidth()
{
	return width;
}

int Paddle::getHeight()
{
	return height;
}

void Paddle::drawPaddle(sf::RenderWindow & win)
{
	win.draw(paddleShape);
}

void Paddle::setPosPaddle(int x, int y)
{
	setPosition(x, y);
	paddleShape.setPosition(x, y);
	//std::cout << xPos <<  " " << yPos << std::endl;
	// float newOriginX = x + width/2;
	// float newOriginY = y + height/2;
	
	sf::FloatRect r = paddleShape.getLocalBounds();
	std::cout << r.left <<  " "  << r.top << std::endl;
	// std::cout << paddleShape.getOrigin().x << " " << paddleShape.getOrigin().y << std::endl; 
}

void Paddle::loadTexture(std::string shapeTexture)
{
	paddleTexture.loadFromFile(shapeTexture);
	paddleShape.setTexture(&paddleTexture);
}

void Paddle::movePaddleInDirection()
{
	paddleShape.move(xSpeed, ySpeed);
	position.setX(position.getX()+xSpeed);
	position.setY(position.getY()+ySpeed);
	//std::cout << xPos <<  " " << yPos << std::endl;	
}

bool Paddle::checkIfBallWithinBounds(Ball & b)
{
	std::pair <float, float> ballCenter = b.getCenter();

	int circleDistanceX = std::abs(ballCenter.first - xPos);
	int circleDistanceY = std::abs(ballCenter.second - yPos);

    if (circleDistanceX > (width/2 + b.getRadius())) { return false; }
    if (circleDistanceY > (height/2 + b.getRadius())) { return false; }

    if (circleDistanceX <= (width/2)) { return true; } 
    if (circleDistanceY <= (height/2)) { return true; }

    int cornerDistance_sq = pow((circleDistanceX - width/2),2) +
                         pow((circleDistanceY - height/2),2);

    return (cornerDistance_sq <= (b.getRadius()^2));

}

// void Paddle::CheckCollisionWithBall(Ball & b)
// {
	

// 	//DISTANCE FROM THE CENTER OF TEH BALL!!
// 	//cout b.getCenter.second;

// 	//if (b.getDistanceFromCenter(xPos, yPos);)

// 	if(checkIfBallWithinBounds(b) == true)
// 	{
// 		std::cout << "HEYOOOOOOOOOOOOOOO" << std::flush;
// 	}
// 	// float first = b.getCenter().first;//X
// 	// float second = b.getCenter().second;//Y
// 	// if(first > xPos-5 && first < xPos + width+5  && (yPos < b.getCenter().second+b.getRadius()))
// 	// {
// 	// 	b.setSpeed(0, b.getYSpeed()*-1, false, true);
// 	// }

// 	// if(first+b.getRadius() < xPos+5  && xPos-first < b.getRadius() +10 && second+b.getRadius() > yPos)
// 	// {
// 	// 	//std::cout<<"WOOOO"<< std::endl;
// 	// 	b.setSpeed(b.getXSpeed()*-1, 0, true, false);
// 	// 	//std::cout << height << " " << width << " " << xPos <<" " << " " << b.getRadius();
// 	// }

// 	// //sstd::cout << (first-xPos+width < b.getRadius() +5)<< std::endl;
// 	// bool one = (first-b.getRadius() > xPos+width);
// 	//  float radius =  b.getRadius() +5;
// 	//  float daWith = xPos+width;
// 	//  float theMinus = first-xPos+width;

// 	// bool two = (first-xPos+150 < b.getRadius() +315);
// 	// std::cout << radius << " " << theMinus << " " << two <<" " <<first <<  " " << xPos <<  std::endl;
// 	// bool three = second+b.getRadius() > yPos;
	
// 	// float newWidth = width;
// 	// float yes = first-(xPos+newWidth);
	
// 	// std::cout << one << " " << two << " " << three << " "  << yes << std::endl;
// 	// if(one && two && three)
// 	// {
// 	// 	std::cout<<"WOOOO2"<< std::endl;
// 	// 	b.setSpeed(b.getXSpeed()*-1, 0, true, false);
// 	// }
// 	// float distanceToTopLeft = b.getDistanceFromCenter(xPos, yPos);
// 	// float distanceToTopRight = b.getDistanceFromCenter(xPos+width, yPos);//Right COrner
// 	// float distanceToBottomLeft = b.getDistanceFromCenter(xPos, yPos+height);//Bottom left
// 	// float distanceToBottomRight =b.getDistanceFromCenter(xPos+width, yPos+height);//Distance form lower corner

// 	// if((distanceToTopLeft < b.getRadius() && distanceToBottomLeft > b.getRadius()) || (distanceToTopRight < b.getRadius() && distanceToBottomRight > b.getRadius()) )
// 	// {
		
// 	// }
// 	// else if((distanceToBottomRight < b.getRadius() && distanceToTopRight > b.getRadius()) || (distanceToBottomLeft < b.getRadius() && distanceToTopLeft > b.getRadius()))
// 	// {
// 	// 	b.setSpeed(b.getXSpeed()*-1, 0, true, false);
// 	// }

// }
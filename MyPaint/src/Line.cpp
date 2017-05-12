/*
 * Line.cpp
 *
 *  Created on: 23 лют. 2017
 *      Author: TheXIFC
 */

#include "Line.h"

Line::Line(sf::RenderWindow* window) : Primitive(window) {}

Line::Line(sf::RenderWindow* window, int x1, int y1, int x2, int y2) : Primitive(window, x1, y1, x2, y2) {}

Line::~Line() {
	// TODO Auto-generated destructor stub
}

void Line::draw() {
	window->draw(rectangle);
	window->draw(circle1);
	window->draw(circle2);
}

void Line::refresh() {
	rectangle.setSize(sf::Vector2f(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)), width));
	double angleD; //rotation angle in degrees
	//counting rotation angle
	if (x1 == x2) {
		angleD = 90;
		if (y1 > y2)
			angleD += 180;
	}
	else {
		angleD = atan(((double) y2-y1)/(x2-x1))*57.2958;//radians to degrees cast coefficient
		if (x1 > x2)
			angleD += 180;
	}
	rectangle.setRotation(angleD);

	//counting rect position
	double angleR = angleD/57.2958; //rotation angle in radians
	rectangle.setPosition(x1 + width*sin(angleR)/2, y1 - width*cos(angleR)/2);

	//setting circles
	circle1.setRadius(width/2);
	circle2.setRadius(width/2);
	circle1.setPosition(x1 - width/2, y1 - width/2);
	circle2.setPosition(x2 - width/2, y2 - width/2);
}

void Line::setColor(sf::Color color) {
	rectangle.setFillColor(color);
	circle1.setFillColor(color);
	circle2.setFillColor(color);
}

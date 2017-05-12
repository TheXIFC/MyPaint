/*
 * Rectangle.cpp
 *
 *  Created on: 24 лют. 2017
 *      Author: TheXIFC
 */

#include "Rectangle.h"


Rectangle::Rectangle(sf::RenderWindow* window) : Primitive(window) {
}

Rectangle::Rectangle(sf::RenderWindow* window, int x1, int y1, int x2, int y2) :
		Primitive(window, x1, y1, x2, y2) {
}

Rectangle::~Rectangle() {
	// TODO Auto-generated destructor stub
}

void Rectangle::draw() {
	window->draw(rectangle);
}

void Rectangle::refresh() {
	rectangle.setSize(sf::Vector2f(abs(x2-x1), abs(y2-y1)));
	rectangle.setPosition(x1<x2?x1:x2, y1<y2?y1:y2);
}

void Rectangle::setColor(sf::Color color) {
	rectangle.setFillColor(color);
}

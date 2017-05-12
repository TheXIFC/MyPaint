/*
 * Ellipse.cpp
 *
 *  Created on: 27 лют. 2017
 *      Author: TheXIFC
 */

#include "Ellipse.h"

Ellipse::Ellipse(sf::RenderWindow* window) :Primitive(window) {
}

Ellipse::Ellipse(sf::RenderWindow* window, int x1, int y1, int x2, int y2) :
	Primitive(window, x1, y1, x2, y2) {
}

Ellipse::~Ellipse() {
	// TODO Auto-generated destructor stub
}

void Ellipse::draw() {
	window->draw(ellipse);
}

void Ellipse::refresh() {
	int width = abs(x2-x1);
	int height = abs(y2-y1);
	int minValue = width<height?width:height;

	ellipse.setRadius(minValue/2);
	ellipse.setPosition(x1<x2?x1:x2, y1<y2?y1:y2);
	ellipse.setScale((float) width/minValue, (float) height/minValue);
}

void Ellipse::setColor(sf::Color color) {
	ellipse.setFillColor(color);
	ellipse.setOutlineColor(color);
}

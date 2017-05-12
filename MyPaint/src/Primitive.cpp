/*
 * Priitive.cpp
 *
 *  Created on: 23 лют. 2017
 *      Author: TheXIFC
 */

#include "Primitive.h"
#include <iostream>

Primitive::Primitive(sf::RenderWindow* window) {
	this->window = window;
	width = 1;
	x1 = x2 = y1 = y2 = 0;

}

Primitive::Primitive(sf::RenderWindow* window, int x1, int y1, int x2, int y2) {
	this->window = window;
	width = 1;

	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;

	this->refresh();
}

Primitive::~Primitive() {
	// TODO Auto-generated destructor stub
}

void Primitive::rescale(int x, int y) {
	this->x2 += x;
	this->y2 += y;
	this->refresh();
}

void Primitive::setWidth(int width) {
	if (width > 0)
		this->width = width;
	refresh();
}

void Primitive::refresh() {
}

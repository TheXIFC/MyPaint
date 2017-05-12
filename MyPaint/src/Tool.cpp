/*
 * Tool.cpp
 *
 *  Created on: 25 лют. 2017
 *      Author: TheXIFC
 */

#include "Tool.h"


Tool::Tool(sf::RenderWindow* window, int x, int y, int width, int height) {
	this->window = window;
	rectangle.setPosition(x, y);
	rectangle.setSize(sf::Vector2f(width, height));

	rect.left = x;
	rect.top = y;
	rect.width = width;
	rect.height = height;
}

Tool::~Tool() {
	// TODO Auto-generated destructor stub
}

void Tool::setChosen(bool b) {
	if (b) {
		rectangle.setOutlineThickness(2);
		rectangle.setOutlineColor(sf::Color(0, 0, 0));
	}
	else
		rectangle.setOutlineThickness(0);
}

bool Tool::contains(int x, int y) {
	return rect.contains(x, y);
}

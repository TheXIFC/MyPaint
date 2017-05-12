/*
 * EllipseTool.cpp
 *
 *  Created on: 27 лют. 2017
 *      Author: TheXIFC
 */

#include "EllipseTool.h"

EllipseTool::EllipseTool(sf::RenderWindow* window, int x, int y, int width, int height) :
	Tool(window, x, y, width, height) {
	ellipse.setPosition(x + 2, y + 2);
	ellipse.setRadius((width<height?width:height)/2 - 2);
	ellipse.setFillColor(sf::Color(255, 0, 0));
}

EllipseTool::~EllipseTool() {
	// TODO Auto-generated destructor stub
}

Primitive* EllipseTool::getPrimitive(int x1, int y1, int x2, int y2) {
	return new Ellipse(window, x1, y1, x2, y2);
}

void EllipseTool::draw() {
	window->draw(rectangle);
	window->draw(ellipse);
}

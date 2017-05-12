/*
 * RectangleTool.cpp
 *
 *  Created on: 27 лют. 2017
 *      Author: TheXIFC
 */

#include "RectangleTool.h"

RectangleTool::RectangleTool(sf::RenderWindow* window, int x, int y, int width, int height) :
	Tool(window, x, y, width, height) {
	symbol.setPosition(x + 5, y + 10);
	symbol.setSize(sf::Vector2f(width - 10, height - 20));
	symbol.setFillColor(sf::Color(0, 255, 0));
}

RectangleTool::~RectangleTool() {
	// TODO Auto-generated destructor stub
}

Primitive* RectangleTool::getPrimitive(int x1, int y1, int x2, int y2) {
	return new Rectangle(window, x1, y1, x2, y2);
}

void RectangleTool::draw() {
	window->draw(rectangle);
	window->draw(symbol);
}

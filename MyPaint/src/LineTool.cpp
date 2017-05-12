/*
 * LineTool.cpp
 *
 *  Created on: 27 лют. 2017
 *      Author: TheXIFC
 */

#include "LineTool.h"

LineTool::LineTool(sf::RenderWindow* window, int x, int y, int width, int height) :
	Tool(window, x, y, width, height) {
	line = new Line(window, x + 2, y + 2, x + width - 2, y + height - 2);
	line->setColor(sf::Color(0, 0, 255));
	line->setWidth(3);
}

LineTool::~LineTool() {
	delete line;
}

Primitive* LineTool::getPrimitive(int x1, int y1,
		int x2, int y2) {
	return new Line(window, x1, y1, x2, y2);

}

void LineTool::draw() {
	window->draw(rectangle);
	line->draw();
}

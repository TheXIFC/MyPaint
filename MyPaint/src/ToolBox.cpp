/*
 * ToolBox.cpp
 *
 *  Created on: 24 лют. 2017
 *      Author: TheXIFC
 */

#include "SFML/Graphics.hpp"
#include "ToolBox.h"

ToolBox::ToolBox(sf::RenderWindow* window) {
	this->window = window;
	initialize();

	fieldsList.push_back(redNumberField);
	fieldsList.push_back(greenNumberField);
	fieldsList.push_back(blueNumberField);
	fieldsList.push_back(widthField);
	currentDigitField = nullptr;

	toolList.push_back(lineTool);
	toolList.push_back(rectangleTool);
	toolList.push_back(ellipseTool);
	currentTool = lineTool;
	currentTool->setChosen(true);

	colorExample.setPosition(5, 40);
	colorExample.setSize(sf::Vector2f(155, 20));
	colorExample.setOutlineThickness(2);
	colorExample.setOutlineColor(sf::Color(0, 0, 0));

	rectangle.setPosition(0, 0);
	rectangle.setSize(sf::Vector2f(375, 75));
	rectangle.setFillColor(sf::Color(128, 128, 128));
	rect.left = rect.top = 0;
	rect.width = 375;
	rect.height = 75;
}

void ToolBox::initialize() {
	redNumberField = new DigitField(window, 5, 5, 30, 20);
	redNumberField->setTextColor(sf::Color(255, 0, 0));
	greenNumberField = new DigitField(window, 45, 5, 30, 20);
	greenNumberField->setTextColor(sf::Color(0, 255, 0));
	blueNumberField = new DigitField(window, 85, 5, 30, 20);
	blueNumberField->setTextColor(sf::Color(0, 0, 255));
	widthField = new DigitField(window, 125, 5, 30, 20);
	widthField->setLimits(0, 999);

	lineTool = new LineTool(window, 200, 5, 40, 40);
	rectangleTool = new RectangleTool(window, 250, 5, 40, 40);
	ellipseTool = new EllipseTool(window, 300, 5, 40, 40);
}

ToolBox::~ToolBox() {
	for (unsigned int i = 0; i < fieldsList.size(); i++)
		delete fieldsList[i];

	for (unsigned int i = 0; i < toolList.size(); i++)
		delete toolList[i];
}

void ToolBox::handleMouseButtonEvent(
		sf::Event::MouseButtonEvent mouseButtonEvent) {
	int x = mouseButtonEvent.x, y = mouseButtonEvent.y;

	if (currentDigitField != nullptr) {
		currentDigitField->setChosen(false);
		currentDigitField = nullptr;
	}

	for (unsigned int i = 0; i < fieldsList.size(); i++) {
		if (fieldsList[i]->contains(x,y)) {
			currentDigitField = fieldsList[i];
			currentDigitField->setChosen(true);
			return;
		}
	}

	for (unsigned int i = 0; i < toolList.size(); i++) {
		if (toolList[i]->contains(x, y)) {
			if (currentTool != nullptr)
				currentTool->setChosen(false);
			currentTool = toolList[i];
			currentTool->setChosen(true);
		}
	}
}

void ToolBox::handleMouseMoveEvent(sf::Event::MouseMoveEvent mouseMoveEvent) {
}

void ToolBox::draw() {
	window->draw(rectangle);
	colorExample.setFillColor(getColor());
	window->draw(colorExample);

	for (unsigned int i = 0; i < fieldsList.size(); i++)
		fieldsList[i]->draw();

	for (unsigned int i = 0; i < toolList.size(); i++)
		toolList[i]->draw();
}

void ToolBox::handleKeyEvent(sf::Event::KeyEvent keyEvent) {
	if (currentDigitField != nullptr && keyEvent.code == sf::Keyboard::BackSpace) {
		currentDigitField->deleteLast();
	}
}

void ToolBox::handleTextEntered(sf::Event::TextEvent textEvent) {
	if (textEvent.unicode < 128 && currentDigitField != nullptr)
		currentDigitField->addChar((char) textEvent.unicode);
}

sf::Color ToolBox::getColor() {
	sf::Color color(redNumberField->getValue(), greenNumberField->getValue(), blueNumberField->getValue());
	return color;
}

int ToolBox::getWidth() {
	return widthField->getValue();
}

Primitive* ToolBox::getPrimitive(int x1, int y1, int x2, int y2) {
	return currentTool->getPrimitive(x1, y1, x2, y2);
}

bool ToolBox::contains(int x, int y) {
	return rect.contains(x, y);
}

/*
 * DrawingDeck.cpp
 *
 *  Created on: 24 лют. 2017
 *      Author: TheXIFC
 */

#include "DrawingDeck.h"

DrawingDeck::DrawingDeck(sf::RenderWindow* window, ToolBox* toolBox) {
	this->window = window;
	this->toolBox = toolBox;
	currentPrimitive = nullptr;
}

DrawingDeck::~DrawingDeck() {
	delete currentPrimitive;
	while (!primitives.empty()) {
		delete primitives.back();
		primitives.pop_back();
	}
}

void DrawingDeck::handleMouseButtonEvent(
		sf::Event::MouseButtonEvent mouseButtonEvent) {
	if (mouseButtonEvent.button == sf::Mouse::Left) {
		int x = mouseButtonEvent.x;
		int y = mouseButtonEvent.y;
		lastMousePos[0] = x;
		lastMousePos[1] = y;
		currentPrimitive = toolBox->getPrimitive(x, y, x, y);
		currentPrimitive->setColor(toolBox->getColor());
		currentPrimitive->setWidth(toolBox->getWidth());
	}
}


void DrawingDeck::handleMouseMoveEvent(
		sf::Event::MouseMoveEvent mouseMoveEvent) {
	if (currentPrimitive != nullptr) {
		currentPrimitive->rescale(mouseMoveEvent.x - lastMousePos[0], mouseMoveEvent.y - lastMousePos[1]);
		lastMousePos[0] = mouseMoveEvent.x;
		lastMousePos[1] = mouseMoveEvent.y;
	}
}

void DrawingDeck::handleMouseButtonReleased() {
	if (currentPrimitive != nullptr) {
		primitives.push_back(currentPrimitive);
		currentPrimitive = nullptr;
	}
}

void DrawingDeck::draw() {
	for (unsigned int i = 0; i < primitives.size(); i++) {
		primitives[i]->draw();
	}

	if (currentPrimitive != nullptr)
		currentPrimitive->draw();
}

void DrawingDeck::clear() {
	primitives.clear();
}

void DrawingDeck::deleteLast() {
	if (primitives.size() != 0)
		primitives.pop_back();
}

void DrawingDeck::handleKeyEvent(sf::Event::KeyEvent keyEvent) {
	if (keyEvent.control && keyEvent.code == sf::Keyboard::Z)
		deleteLast();
	else if (keyEvent.code == sf::Keyboard::Delete) {
		primitives.clear();
	}
}

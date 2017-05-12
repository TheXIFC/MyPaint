/*
 * DrawingDeck.h
 *
 *  Created on: 24 лют. 2017
 *      Author: TheXIFC
 */

#ifndef DRAWINGDECK_H_
#define DRAWINGDECK_H_

#include "SFML/Graphics.hpp"
#include "ToolBox.h"
#include "Primitive.h"
#include "Rectangle.h"
#include "Line.h"
#include "Ellipse.h"
#include "EventHandler.h"

class DrawingDeck : public EventHandler {
private:
	sf::RenderWindow* window;
	ToolBox* toolBox;
	std::vector<Primitive*> primitives;
	Primitive* currentPrimitive;
	int lastMousePos[2]; //last mouse position x and y
public:
	DrawingDeck(sf::RenderWindow*, ToolBox*);
	virtual ~DrawingDeck();
	void handleMouseButtonEvent(sf::Event::MouseButtonEvent);
	void handleMouseMoveEvent(sf::Event::MouseMoveEvent);
	void handleMouseButtonReleased();
	void handleKeyEvent(sf::Event::KeyEvent);
	void draw();
	void clear();
	void deleteLast();
};

#endif /* DRAWINGDECK_H_ */

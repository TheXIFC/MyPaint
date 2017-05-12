/*
 * ToolBox.h
 *
 *  Created on: 24 лют. 2017
 *      Author: TheXIFC
 */

#ifndef TOOLBOX_H_
#define TOOLBOX_H_

#include "SFML/Graphics.hpp"

#include "EventHandler.h"
#include "DigitField.h"
#include "Tool.h"
#include "LineTool.h"
#include "RectangleTool.h"
#include "EllipseTool.h"

class ToolBox : public EventHandler {
private:
	sf::RenderWindow* window;

	sf::RectangleShape rectangle;
	sf::Rect<int> rect;
	sf::RectangleShape colorExample;

	std::vector<DigitField*> fieldsList;
	DigitField* redNumberField;
	DigitField* greenNumberField;
	DigitField* blueNumberField;
	DigitField* widthField;
	DigitField* currentDigitField;

	std::vector<Tool*> toolList;
	LineTool* lineTool;
	RectangleTool* rectangleTool;
	EllipseTool* ellipseTool;
	Tool* currentTool;

	void initialize();
public:
	ToolBox(sf::RenderWindow*);
	virtual ~ToolBox();
	void handleMouseButtonEvent(sf::Event::MouseButtonEvent);
	void handleMouseMoveEvent(sf::Event::MouseMoveEvent);
	void handleKeyEvent(sf::Event::KeyEvent);
	void handleTextEntered(sf::Event::TextEvent);
	void draw();
	sf::Color getColor();
	int getWidth();
	Primitive* getPrimitive(int, int, int, int);
	bool contains(int x, int y);
};

#endif /* TOOLBOX_H_ */

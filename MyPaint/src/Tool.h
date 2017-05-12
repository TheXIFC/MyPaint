/*
 * Tool.h
 *
 *  Created on: 25 лют. 2017
 *      Author: TheXIFC
 */

#ifndef TOOL_H_
#define TOOL_H_

#include "SFML/Graphics.hpp"
#include "Primitive.h"

class Tool {
protected:
	sf::RenderWindow* window;
	sf::RectangleShape rectangle;
	sf::Rect<int> rect;
public:
	Tool(sf::RenderWindow*, int, int, int ,int);
	virtual ~Tool();
	virtual Primitive* getPrimitive(int, int, int, int) = 0;
	virtual void draw() = 0;
	virtual void setChosen(bool);
	bool contains(int x, int y);
};

#endif /* TOOL_H_ */

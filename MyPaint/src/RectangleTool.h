/*
 * RectangleTool.h
 *
 *  Created on: 27 лют. 2017
 *      Author: TheXIFC
 */

#ifndef RECTANGLETOOL_H_
#define RECTANGLETOOL_H_

#include "Tool.h"
#include "Rectangle.h"

class RectangleTool: public Tool {
sf::RectangleShape symbol;//symbol of tool
public:
	RectangleTool(sf::RenderWindow*, int, int, int, int);
	virtual ~RectangleTool();
	Primitive* getPrimitive(int, int, int, int);
	void draw();
};

#endif /* RECTANGLETOOL_H_ */

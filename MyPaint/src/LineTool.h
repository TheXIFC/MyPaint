/*
 * LineTool.h
 *
 *  Created on: 27 лют. 2017
 *      Author: TheXIFC
 */

#ifndef LINETOOL_H_
#define LINETOOL_H_

#include "Tool.h"
#include "Line.h"

class LineTool: public Tool {
private:
	Line* line;//symbol of tool
public:
	LineTool(sf::RenderWindow*, int, int, int, int);
	virtual ~LineTool();
	Primitive* getPrimitive(int, int, int, int);
	void draw();

};

#endif /* LINETOOL_H_ */

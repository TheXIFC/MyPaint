/*
 * EllipseTool.h
 *
 *  Created on: 27 лют. 2017
 *      Author: TheXIFC
 */

#ifndef ELLIPSETOOL_H_
#define ELLIPSETOOL_H_

#include "Tool.h"
#include "Ellipse.h"

class EllipseTool: public Tool {
private:
	sf::CircleShape ellipse;//symbol of tool
public:
	EllipseTool(sf::RenderWindow*, int, int, int ,int);
	virtual ~EllipseTool();
	Primitive* getPrimitive(int, int, int, int);
	void draw();
};

#endif /* ELLIPSETOOL_H_ */

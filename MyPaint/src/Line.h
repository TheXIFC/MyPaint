/*
 * Line.h
 *
 *  Created on: 23 лют. 2017
 *      Author: TheXIFC
 */

#ifndef LINE_H_
#define LINE_H_

#include "Primitive.h"
#include <cmath>
#include <iostream>

class Line: public Primitive {
private:
	sf::RectangleShape rectangle;
	sf::CircleShape circle1, circle2;
public:
	Line(sf::RenderWindow* window);
	Line(sf::RenderWindow* window, int x1, int y1, int x2, int y2);
	virtual ~Line();
	void draw();
	void refresh();
	void setColor(sf::Color);
};

#endif /* LINE_H_ */

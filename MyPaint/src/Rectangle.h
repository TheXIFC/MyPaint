/*
 * Rectangle.h
 *
 *  Created on: 24 лют. 2017
 *      Author: TheXIFC
 */

#ifndef RECTANGLE_H_
#define RECTANGLE_H_

#include <cmath>
#include "Primitive.h"

class Rectangle: public Primitive {
private:
	sf::RectangleShape rectangle;
public:
	Rectangle(sf::RenderWindow*);
	Rectangle(sf::RenderWindow*, int, int, int, int);
	virtual ~Rectangle();
	void draw();
	void refresh();
	void setColor(sf::Color);

};

#endif /* RECTANGLE_H_ */

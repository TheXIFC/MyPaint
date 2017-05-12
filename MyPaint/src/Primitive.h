/*
 * Primitive.h
 *
 *  Created on: 23 лют. 2017
 *      Author: TheXIFC
 */

#ifndef PRIMITIVE_H_
#define PRIMITIVE_H_

#include "SFML/Graphics.hpp"

class Primitive {
protected:
	int x1, y1, x2, y2, width;
	sf::RenderWindow* window;
public:
	Primitive(sf::RenderWindow* window);
	Primitive(sf::RenderWindow* window, int x1, int y1, int x2, int y2);
	virtual ~Primitive();
	void setWidth(int width);
	void rescale(int x, int y); //changing values of x2 and y2
	virtual void draw() = 0;
	virtual void refresh(); //recount coefficients and figure positions due to parameters
	virtual void setColor(sf::Color) = 0;

};

#endif /* PRIMITIVE_H_ */

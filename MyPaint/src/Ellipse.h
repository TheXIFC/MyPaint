/*
 * Ellipse.h
 *
 *  Created on: 27 лют. 2017
 *      Author: TheXIFC
 */

#ifndef ELLIPSE_H_
#define ELLIPSE_H_

#include <cmath>
#include "Primitive.h"

class Ellipse : public Primitive {
private:
	sf::CircleShape ellipse;
public:
	Ellipse(sf::RenderWindow*);
	Ellipse(sf::RenderWindow*, int, int, int, int);
	virtual ~Ellipse();
	void draw();
	void refresh();
	void setColor(sf::Color);
};

#endif /* ELLIPSE_H_ */

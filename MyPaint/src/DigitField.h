/*
 * DigitField.h
 *
 *  Created on: 25 лют. 2017
 *      Author: TheXIFC
 */

#ifndef DIGITFIELD_H_
#define DIGITFIELD_H_

#include <sstream>
#include "SFML/Graphics.hpp"
#include "MyFont.h"

class DigitField {
private:
	int value, min_value, max_value;
	sf::Rect<int> rect;
	sf::RectangleShape rectangle;
	sf::Text text;
	sf::RenderWindow* window;
public:
	DigitField(sf::RenderWindow*, int, int, int, int);
	virtual ~DigitField();
	void addChar(char);
	void deleteLast();
	void draw();
	bool contains(int, int);
	void setChosen(bool);
	int getValue();
	void setTextColor(sf::Color);
	void refresh();
	void setLimits(int, int);
};

#endif /* DIGITFIELD_H_ */

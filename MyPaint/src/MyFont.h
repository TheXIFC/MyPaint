/*
 * MyFont.h
 *
 *  Created on: 27 лют. 2017
 *      Author: TheXIFC
 */

#ifndef MYFONT_H_
#define MYFONT_H_

#include "SFML/Graphics.hpp"

class MyFont {
public:
	static sf::Font font;
	MyFont();
	virtual ~MyFont();
	static void initialize();
};

#endif /* MYFONT_H_ */

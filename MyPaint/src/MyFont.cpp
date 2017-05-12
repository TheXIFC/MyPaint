/*
 * MyFont.cpp
 *
 *  Created on: 27 лют. 2017
 *      Author: TheXIFC
 */

#include "MyFont.h"

sf::Font MyFont::font;

MyFont::MyFont() {
	// TODO Auto-generated constructor stub

}

MyFont::~MyFont() {
	// TODO Auto-generated destructor stub
}

void MyFont::initialize() {
	font.loadFromFile("arial.ttf");
}

/*
 * DigitField.cpp
 *
 *  Created on: 25 лют. 2017
 *      Author: TheXIFC
 */

#include "DigitField.h"

DigitField::DigitField(sf::RenderWindow* window, int x, int y, int width, int height) {
	this->window = window;

	value = 0;
	min_value = 0;
	max_value = 255;
	text.setFont(MyFont::font);

	rect.left = x;
	rect.top = y;
	rect.width = width;
	rect.height = height;

	rectangle.setPosition(x, y);
	rectangle.setSize(sf::Vector2f(width, height));

	text.setPosition(x + 2, y + 2);
	text.setCharacterSize(15);
	text.setColor(sf::Color(0,0,0));
}

DigitField::~DigitField() {
	// TODO Auto-generated destructor stub
}

void DigitField::addChar(char ch) {
	if (isdigit(ch)) {
		int digit = ch - '0'; //char to int
		value = value * 10 + digit;
		refresh();
	}

}

void DigitField::draw() {
	window->draw(rectangle);
	window->draw(text);
}

bool DigitField::contains(int x, int y) {
	return rect.contains(x, y);
}

void DigitField::deleteLast() {
	value /= 10;
	refresh();
}

void DigitField::setChosen(bool b) {
	if (b) {
		rectangle.setOutlineThickness(2);
		rectangle.setOutlineColor(sf::Color(0, 0, 0));
	}
	else
		rectangle.setOutlineThickness(0);
}

int DigitField::getValue() {
	return value;
}

void DigitField::setTextColor(sf::Color color) {
	text.setColor(color);
}

void DigitField::refresh() {
	if (value > this->max_value)
		value = this->max_value;
	if (value < this->min_value)
		value = this->min_value;

	std::ostringstream stream;
	stream << value;
	text.setString(stream.str());
}

void DigitField::setLimits(int min, int max) {
	min_value = min;
	max_value = max;
}

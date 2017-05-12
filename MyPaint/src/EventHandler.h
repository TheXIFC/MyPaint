/*
 * Handler.h
 *
 *  Created on: 24 лют. 2017
 *      Author: TheXIFC
 */

#ifndef EVENTHANDLER_H_
#define EVENTHANDLER_H_

#include "SFML/Graphics.hpp"

class EventHandler {
public:
	EventHandler();
	virtual ~EventHandler();
	virtual void handleMouseButtonEvent(sf::Event::MouseButtonEvent) = 0;
	virtual void handleMouseMoveEvent(sf::Event::MouseMoveEvent);
	virtual void handleMouseButtonReleased();
	virtual void handleKeyEvent(sf::Event::KeyEvent);
	virtual void handleTextEntered(sf::Event::TextEvent);
};

#endif /* EVENTHANDLER_H_ */

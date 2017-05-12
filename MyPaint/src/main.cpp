#include "SFML/Graphics.hpp"
#include <vector>

#include "ToolBox.h"
#include "DrawingDeck.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "MyPaint");
	MyFont::initialize();
	ToolBox toolBox(&window);
	DrawingDeck drawingDeck(&window, &toolBox);


	//main loop
	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case (sf::Event::Closed) :
					window.close();
					break;

				case (sf::Event::MouseButtonPressed) :
					if (toolBox.contains(event.mouseButton.x, event.mouseButton.y))
						toolBox.handleMouseButtonEvent(event.mouseButton);
					else
						drawingDeck.handleMouseButtonEvent(event.mouseButton);
					break;

				case (sf::Event::MouseMoved) :
					drawingDeck.handleMouseMoveEvent(event.mouseMove);
					break;

				case (sf::Event::MouseButtonReleased) :
					drawingDeck.handleMouseButtonReleased();
					break;

				case (sf::Event::KeyPressed) :
					drawingDeck.handleKeyEvent(event.key);
					toolBox.handleKeyEvent(event.key);
					break;

				case (sf::Event::TextEntered) :
					toolBox.handleTextEntered(event.text);
					break;

				default:break;
			}


		}

		window.clear();

		drawingDeck.draw();
		toolBox.draw();

		window.display();
		window.setSize(sf::Vector2u(800,600));
	}

	return 0;
}

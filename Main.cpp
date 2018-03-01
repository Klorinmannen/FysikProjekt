#include"Game.h"

int main() {

	sf::RenderWindow window(sf::VideoMode(1600, 900), "2D Physics Stuff", sf::Style::Default);
	Game game;

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)){

			if (event.type == sf::Event::Closed)
				window.close();
		
		}

		window.clear();

		window.draw(game);

		window.display();

	}

	return 0;

}
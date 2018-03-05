#include"Game.h"

int main() {

	//Check for memory leaks
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	sf::RenderWindow window(sf::VideoMode(1600, 900), "2D Physics Stuff", sf::Style::Default);
	window.setFramerateLimit(60);

	Game game(1);

	//Deltatime
	sf::Clock deltaClock;
	float deltaTime = 0.0f;

	while (window.isOpen()) {

		deltaTime = deltaClock.restart().asSeconds();

		sf::Event event;
		while (window.pollEvent(event)){

			if (event.type == sf::Event::Closed)
				window.close();
		
		}

		//update game state
		game.update(deltaTime);

		//Draw game
		window.clear();

		game.draw(window);

		window.display();

	}

	return 0;

}
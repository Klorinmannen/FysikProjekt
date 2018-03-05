#pragma once

#include<string>
#include<fstream>
#include<vector>
#include<Windows.h>

#include"Scene.h"

class Game {

private:

	//Scene Background
	sf::Texture backgroundTexture;
	sf::RectangleShape background;

	//Scene objects
	std::vector<GameObject*> objects;

	//Used to load in scene from file
	Scene sceneController;

	//Used to check inputs
	sf::Mouse mouse;
	sf::Keyboard keyboard;

	//Bullettype
	std::string bulletType;

	///////////////Private functions//////////////////
	
	//Read inputs
	void inputs();

	//Check collisions between objects
	void collision(int objIndex, int otherIndex);

	//Reload new scenes
	void changeScene(int scene);

	//Clear objects vector
	void clearObjects(void);

public:

	Game(int scene);
	Game();
	~Game();

	//Update the current game state
	void update(float dt);

	void draw(sf::RenderWindow& window);

};
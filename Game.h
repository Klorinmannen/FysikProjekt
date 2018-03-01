#pragma once

#include"Player.h"
#include<string>
#include<fstream>
#include<vector>
#include<Windows.h>
#include"Scene.h"


class Game : public sf::Drawable{

private:

	//Scene objects

	sf::Texture backTexture;
	sf::Sprite backSprite;

	std::vector<GameObject> staticObjects; //obstacles, none moveable objects
	std::vector<PhysicsObject> physObjects; //numbers of targets to hit
	Player player;

	Scene sceneController;
	sf::Mouse mouse;
	sf::Keyboard keyboard;

	//Private functions
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void initScene(int scene);
	void inputs(float dt);
	void changeScene(int scene);
	void collision();
public:
	Game(int scene);
	Game();
	~Game();

	void update(float dt);

};
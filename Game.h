#pragma once

#include"PhysicsObject.h"
#include<string>
#include<fstream>

class Game : public sf::Drawable{

private:

	//Scene objects
	GameObject** objects;
	GameObject test;
	int nrOfObjects;

	//Drawing
	sf::VertexArray vertices;
	int nrOfVertices;

	//Private functions
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void initScene(int scene);
	void initVertices(void);
	void readFile(int scene);

public:

	Game(int scene);
	Game();
	~Game();

	void changeScene(int scene);

};
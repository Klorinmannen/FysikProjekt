#ifndef SCENE_H
#define SCENE_H

#include"SFML\Graphics.hpp"
#include<string>
#include<vector>
#include<fstream>

#include"PhysicsObject.h"

class Scene {

private:

	//Vectors to store data read from file
	std::vector<char> types;
	std::vector<sf::Vector2f> positions;
	std::vector<sf::Vector2f> sizes;
	std::vector<std::string> textures;

	//Misc data read from file
	std::string background;
	float airDensity;
	int nrOfObjects;

	//Private functions
	float readInFloat(std::string line, int& strCounter);
	void loadObjects(std::vector<GameObject*>& objects);
	void readFile(int scene);

public:

	Scene();
	~Scene();

	void clear();
	void initScene(int scene, std::vector<GameObject*>& objects);

	//Get
	std::string getBackground(void) const;
	float getAirDensity(void) const;

};

#endif // !SCENE_H

#ifndef SCENE_H
#define SCENE_H
<<<<<<< HEAD
#include<string>

class Scene
{
private:

	std::string backString;

public:
	Scene();
	~Scene();
	std::string getBackGround();
	
};
=======

#include"SFML\Graphics.hpp"
#include<string>
#include<vector>
#include<fstream>
#include"PhysicsObject.h"

class Scene {

private:

	std::vector<char> types;
	std::vector<sf::Vector2f> positions;
	std::vector<sf::Vector2f> sizes;
	std::vector<std::string> textures;

	std::string background;
	float airDensity;
	int nrOfObjects;

	//Private functions
	float readInFloat(std::string line, int& strCounter);

public:

	Scene();
	~Scene();

	void loadObjects(std::vector<PhysicsObject>* pO,
		std::vector<GameObject>* gO);
	void readFile(int scene);

	//Get
	std::string getBackground(void) const;
	float getAirDensity(void) const;

};

>>>>>>> origin/master
#endif // !SCENE_H

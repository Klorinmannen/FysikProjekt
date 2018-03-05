#include"Scene.h"

Scene::Scene() {

	this->background = "";
	this->airDensity = 0.0f;
	this->nrOfObjects = 0;

}

Scene::~Scene() {



}

void Scene::readFile(int scene) {

	//Open file
	std::ifstream file;
	file.open("Scenes//Scene" + std::to_string(scene) + ".txt");

	//Read the amount of objects
	std::string line = "";
	std::getline(file, line);
	this->nrOfObjects = std::stoi(line);

	//Read the density of the scenes air
	line = "";
	std::getline(file, line);
	this->airDensity = std::stof(line);

	//Read the scenes background texture
	line = "";
	std::getline(file, line);
	this->background = line;

	//Read in all of the scenes initial objects values
	line = "";
	int strCounter = 0;
	sf::Vector2f tempPos = sf::Vector2f(0.0f, 0.0f);
	sf::Vector2f tempSize = sf::Vector2f(0.0f, 0.0f);
	std::string tempLine = "";
	while (std::getline(file, line)) {

		//Read in object type
		this->types.push_back(line.at(strCounter));
		strCounter += 2;

		//Read in x/y position
		tempPos.x = this->readInFloat(line, strCounter);
		tempPos.y = this->readInFloat(line, strCounter);
		this->positions.push_back(tempPos);

		//Read in size x/y
		tempSize.x = this->readInFloat(line, strCounter);
		tempSize.y = this->readInFloat(line, strCounter);
		this->sizes.push_back(tempSize);

		//Read in texture
		while (line.at(strCounter) != ',') {

			tempLine += line.at(strCounter);
			strCounter++;

		}
		this->textures.push_back(tempLine);

		//Reset vars
		line = "";
		strCounter = 0;
		tempLine = "";
		tempPos = sf::Vector2f(0.0f, 0.0f);
		tempSize = sf::Vector2f(0.0f, 0.0f);

	}

	//Close file
	file.close();

}

float Scene::readInFloat(std::string line, int& strCounter) {

	float result = 0.0f;
	std::string tempLine = "";

	while (line.at(strCounter) != ',') {

		tempLine += line.at(strCounter);
		strCounter++;

	}
	result = std::stof(tempLine);
	strCounter++;

	return result;

}

void Scene::loadObjects(std::vector<GameObject*>& objects) {

	int counter = 0;

	while (counter < this->nrOfObjects) {

		switch (this->types[counter]) {
		case 'G':

			objects.push_back(new GameObject(this->positions[counter],
				this->sizes[counter], this->textures[counter]));

			break;

		case 'P':
			
			objects.push_back(new PhysicsObject(this->positions[counter],
				this->sizes[counter], this->textures[counter]));
			
			break;

		default:
			break;

		}

		counter++;

	}

}

void Scene::initScene(int scene, std::vector<GameObject*>& objects) {

	this->readFile(scene);
	this->loadObjects(objects);

}

void Scene::clear() {

	//Reset vars
	this->nrOfObjects = 0;
	this->airDensity = 0.0f;
	this->background = "";

	//Reset object data
	this->types.clear();
	this->positions.clear();
	this->sizes.clear();
	this->textures.clear();

}

std::string Scene::getBackground(void) const{

	return this->background;

}

float Scene::getAirDensity(void) const{

	//Different air density for each scene
	//Scene 1 Air: 1.225kg/m^3
	//Scene 2 Chlorine gas: 2.994kg/m^3
	//Scene 3 Water: 998.0 kg/m^3

	return this->airDensity;

}

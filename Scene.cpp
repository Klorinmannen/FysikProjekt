#include"Scene.h"

Scene::Scene() {



}

Scene::~Scene() {



}

void Scene::readFile(int scene) {

	//Open file
	std::ifstream file;
	file.open("Scene" + std::to_string(scene) + ".txt");

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
	int counter = 0;
	int strCounter = 0;
	while (std::getline(file, line)) {

		//Read in object type
		this->types[counter] = line.at(strCounter);
		strCounter += 2;

		//Read in x position
		this->positions[counter].x = this->readInFloat(line, strCounter);
		
		//Read in y position
		this->positions[counter].y = this->readInFloat(line, strCounter);

		//Read in size x
		this->sizes[counter].x = this->readInFloat(line, strCounter);

		//Read in x position
		this->sizes[counter].y = this->readInFloat(line, strCounter);

		//Read in texture
		std::string tempLine = "";
		while (line.at(strCounter) != ',') {

			tempLine += line.at(strCounter);
			this->textures[counter] = tempLine;

		}

		//Reset line and counter
		line = "";
		strCounter = 0;

	}

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

void Scene::loadObjects(std::vector<PhysicsObject*>* pO, std::vector<GameObject>* gO) {

	int counter = 0;

	while (counter < this->nrOfObjects) {

		switch (this->types.at[counter]) {
		case 'G':

			gO->push_back(GameObject(this->positions.at[counter],
				this->sizes[counter], this->textures[counter]));
			break;

		case 'P':

			gO->push_back(PhysicsObject(this->positions.at[counter],
				this->sizes[counter], this->textures[counter]));
			break;

		default:
			break;

		}

		counter++;

	}

}

std::string Scene::getBackground(void) const{

	return this->background;

}

float Scene::getAirDensity(void) const{

	return this->airDensity;

}
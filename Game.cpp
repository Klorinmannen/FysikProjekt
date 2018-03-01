#include"Game.h"

Game::Game(int scene) {

	this->initScene(scene);
	this->initVertices();

}

Game::Game() {



}

Game::~Game() {



}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const{

	target.draw(this->vertices);

}

void Game::initScene(int scene) {

	test = GameObject(sf::Vector2f(700, 425), sf::Vector2f(100, 30), sf::Color(80, 40, 240));
	this->nrOfObjects = 1;

}

void Game::initVertices() {

	this->nrOfVertices = this->nrOfObjects * 4;
	this->vertices.resize(this->nrOfVertices);
	this->vertices.setPrimitiveType(sf::Quads);

	for (int i = 0; i < this->nrOfVertices; i += 4) {

		this->vertices[i].position = this->test.getPos();
		this->vertices[i + 1].position = sf::Vector2f(this->test.getPos().x, this->test.getPos().y - this->test.getSize().y);
		this->vertices[i + 2].position = sf::Vector2f(this->test.getPos().x + this->test.getSize().x,
			this->test.getPos().y - this->test.getSize().y);
		this->vertices[i + 3].position = sf::Vector2f(this->test.getPos().x + this->test.getSize().x, this->test.getPos().y);

		this->vertices[i].color = this->test.getColor();
		this->vertices[i + 1].color = this->test.getColor();
		this->vertices[i + 2].color = this->test.getColor();
		this->vertices[i + 3].color = this->test.getColor();

	}

}

void Game::changeScene(int scene) {



}

void Game::readFile(int scene) {

	std::ifstream file;
	file.open("Scene" + std::to_string(scene) + ".txt");

	std::string line = "";
	std::getline(file, line);

	this->nrOfObjects = std::stoi(line);

	while (std::getline(file, line)) {



	}

}
#include"Game.h"

Game::Game(int scene) {

	//Load in objecets
	this->sceneController.initScene(1, this->objects);

	//Set background
	this->backgroundTexture.loadFromFile("Textures//" + this->sceneController.getBackground() + ".png");
	this->background.setPosition(0.0f, 0.0f);
	this->background.setSize(sf::Vector2f(1600.0f, 900.0f));
	this->background.setTexture(&this->backgroundTexture);

	//Bullet type
	this->bulletType = "Wood";

}


Game::Game() {
	


}

Game::~Game() {

	this->clearObjects();

}

void Game::update(float dt){

	//Read keyobard/mouse input
	this->inputs();
	
	//Update acceleration
	for (auto obj : this->objects) {

		if (!obj->getIsStatic() && obj != this->objects[0]) {

			static_cast<PhysicsObject*>(obj)->updateAcceleration();

		}

	}

	//Update velocity
	for (auto obj : this->objects) {

		if (!obj->getIsStatic()) {

			static_cast<PhysicsObject*>(obj)->updateVelocity(dt);

		}

	}

	//Check collisions
	int currentIndex = 0;
	for (auto obj : this->objects) {

		//Dont check static walls or player
		if (!obj->getIsStatic() && currentIndex != 0) {

			for (int i = 0; i < this->objects.size(); i++) {

				//Dont check self or player
				if (i != currentIndex && i != 0) {

					this->collision(currentIndex, i);

				}

				i++;

			}

		}

		currentIndex++;

	}

	//Move
	for (auto obj : this->objects) {

		if (!obj->getIsStatic()) {

			static_cast<PhysicsObject*>(obj)->move();

		}

	}

}

void Game::draw(sf::RenderWindow& window) {

	//Draw background
	window.draw(this->background);

	//Draw objects
	for (auto obj : this->objects) {

		obj->draw(window);

	}

}

void Game::inputs(){

	//Check mouse input
	if (this->mouse.isButtonPressed(sf::Mouse::Left)){	//Handle mouse input
	
		this->objects.push_back(new PhysicsObject(this->objects[0]->getCenter(),
			sf::Vector2f(25.0f, 25.0f), this->bulletType));

	}

	//Check player X movement
	if (this->keyboard.isKeyPressed(sf::Keyboard::A)){	//move player left

		static_cast<PhysicsObject*>(this->objects[0])->setVelocity(sf::Vector2f(-8.0f, 
			static_cast<PhysicsObject*>(this->objects[0])->getVelocity().y));

	}
	else if (this->keyboard.isKeyPressed(sf::Keyboard::D)){	//move player right

		static_cast<PhysicsObject*>(this->objects[0])->setVelocity(sf::Vector2f(8.0f, 
			static_cast<PhysicsObject*>(this->objects[0])->getVelocity().y));
	
	}
	else {

		static_cast<PhysicsObject*>(this->objects[0])->setVelocity(sf::Vector2f(0.0f,
			static_cast<PhysicsObject*>(this->objects[0])->getVelocity().y));

	}

	//Check player Y movement
	if (this->keyboard.isKeyPressed(sf::Keyboard::W)) {	//move player up

		static_cast<PhysicsObject*>(this->objects[0])->setVelocity(sf::Vector2f(
			static_cast<PhysicsObject*>(this->objects[0])->getVelocity().x, -8.0f));

	}
	else if (this->keyboard.isKeyPressed(sf::Keyboard::S)) {	//move player down

		static_cast<PhysicsObject*>(this->objects[0])->setVelocity(sf::Vector2f(
			static_cast<PhysicsObject*>(this->objects[0])->getVelocity().x, 8.0f));

	}
	else {

		static_cast<PhysicsObject*>(this->objects[0])->setVelocity(
			sf::Vector2f(static_cast<PhysicsObject*>(this->objects[0])->getVelocity().x, 0.0f));

	}

	//Change scene
	if (this->keyboard.isKeyPressed(sf::Keyboard::Num1)){	//load in scene 1

		this->changeScene(1);

	}
	else if (this->keyboard.isKeyPressed(sf::Keyboard::Num2)){	//Load in scene 2

		this->changeScene(2);
	
	}
	else if (this->keyboard.isKeyPressed(sf::Keyboard::Num3)){	//Load in scene 3

		this->changeScene(3);
	
	}

	//Change bullet type
	if (this->keyboard.isKeyPressed(sf::Keyboard::Z)) {	//Wood bullet

		this->bulletType = "Wood";

	}
	else if (this->keyboard.isKeyPressed(sf::Keyboard::X)) {	//Metal bullet

		this->bulletType = "Metal";

	}
	else if (this->keyboard.isKeyPressed(sf::Keyboard::C)) {	//Gold bullet

		this->bulletType = "Gold";

	}
}

void Game::changeScene(int scene){

	//Reset objects
	this->clearObjects();
	
	//Reset data in scene object
	this->sceneController.clear();

	//Load in new objects
	this->sceneController.initScene(scene, this->objects);

	//update background
	this->backgroundTexture.loadFromFile("Textures//" + this->sceneController.getBackground() + ".png");
	this->background.setTexture(&this->backgroundTexture);

}

void Game::collision(int objIndex, int otherIndex) {

	
	if (this->objects[objIndex]->getBody().getGlobalBounds().
		intersects(this->objects[otherIndex]->getBody().getGlobalBounds())) {

		if (this->objects[objIndex]->getBody().getPosition().x >= 
			this->objects[otherIndex]->getBody().getPosition().x) {

			static_cast<PhysicsObject*>(this->objects[objIndex])->modifyAcceleration(sf::Vector2f(0.0f, 0.0f));

		}

	}

}

void Game::clearObjects(void) {

	while (!this->objects.empty()) {

		delete this->objects.back();
		this->objects.pop_back();

	}
	
}
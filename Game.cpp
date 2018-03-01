#include"Game.h"

Game::Game(int scene) {

	this->initScene(scene);
	this->changeScene(scene);
	this->player.init();
}

Game::Game() 
{
	


}

Game::~Game() {



}

void Game::update(float dt)
{
	this->inputs();
	this->player.update(dt);

}

void Game::draw(sf::RenderTarget& target, sf::RenderStates states) const{

	//draw background
	target.draw(this->backSprite, states);

	//draw objects
	for (auto var : this->physObjects)
	{
		target.draw(var, states);
	}
	for (auto var : this->staticObjects)
	{
		target.draw(var, states);
	}
}

void Game::initScene(int scene) {

	this->sceneController.initiate(scene);
}

void Game::inputs()
{
	//sense inputs
	//[0] is player, set targetpos, move and update current scene
	if (this->mouse.isButtonPressed(sf::Mouse::Left))
	{
		this->player.setTargetPos(this->mouse.getPosition());
	}
	else if (this->keyboard.isKeyPressed(sf::Keyboard::A))
	{
		this->player.moveLeft();
	}
	else if (this->keyboard.isKeyPressed(sf::Keyboard::D))
	{
		this-player.moveRight();
	}
	else if (this->keyboard.isKeyPressed(sf::Keyboard::Num1))
	{
		this->sceneController.reset(1);
		this->changeScene();
	}
	else if (this->keyboard.isKeyPressed(sf::Keyboard::Num2))
	{
		this->sceneController.reset(2);
	}
	else if (this->keyboard.isKeyPressed(sf::Keyboard::Num3))
	{
		this->sceneController.reset(3);
	}
}

void Game::changeScene(int scene)
{
	//reset scene and load new
	this->staticObjects.clear();
	this->physObjects.clear();
	this->sceneController.loadObjects(&this->physObjects, &this->staticObjects);
	
	//update background image
	this->backTexture.loadFromFile(this->sceneController.getBackGround());
	this->backSprite.setTexture(this->backTexture);

}


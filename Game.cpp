#include"Game.h"

Game::Game(int scene) {

	this->initScene(scene);
	this->changeScene(scene);
	this->player 
}

Game::Game() 
{
	


}

Game::~Game() {



}

void Game::update(float dt)
{
	this->inputs(dt);
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

void Game::inputs(float dt)
{
	//sense inputs
	//[0] is player, set targetpos, move and update current scene
	if (this->mouse.isButtonPressed(sf::Mouse::Left))
	{
		this->player.setTargetPos(this->mouse.getPosition());
	}
	else if (this->keyboard.isKeyPressed(sf::Keyboard::A))
	{
		//left
		this->player.movePlayer(Player::direction::left, dt);
	}
	else if (this->keyboard.isKeyPressed(sf::Keyboard::D))
	{
		//right
		this->player.movePlayer(Player::direction::right, dt);
	}
	else if (this->keyboard.isKeyPressed(sf::Keyboard::W))
	{
		//up
		this->player.movePlayer(Player::direction::up, dt);
	}
	else if (this->keyboard.isKeyPressed(sf::Keyboard::S))
	{
		//down
		this->player.movePlayer(Player::direction::down, dt);
	}
	else if (this->keyboard.isKeyPressed(sf::Keyboard::Num1))
	{
		//key 1 - first scene activates / change and load new values
		this->sceneController.reset(Scene::c_scene::first);
		this->changeScene(1);
	}
	else if (this->keyboard.isKeyPressed(sf::Keyboard::Num2))
	{

		this->sceneController.reset(Scene::c_scene::second);
		this->changeScene(2);
	}
	else if (this->keyboard.isKeyPressed(sf::Keyboard::Num3))
	{

		this->sceneController.reset(Scene::c_scene::third);
		this->changeScene(3);
	}
}

void Game::changeScene(int scene)
{
	//reset scene and load new
	this->staticObjects.clear();
	this->physObjects.clear();
	this->sceneController.loadObjects(&this->physObjects, &this->staticObjects);
	
	//update background image
	this->backTexture.loadFromFile(this->sceneController.getBackground());
	this->backSprite.setTexture(this->backTexture);
}

void Game::collision()
{
	//check for collisions between objects and projectile
	this->player.getBulletPos();
}


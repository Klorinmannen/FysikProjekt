#include"GameObject.h"

GameObject::GameObject(sf::Vector2f pos, sf::Vector2f size, std::string texture) {

	this->startPos = pos;
	this->size = size;
	
	this->center = sf::Vector2f(this->startPos.x + (this->size.x / 2.0f),
		this->startPos.y + (this->size.y / 2.0f));

	this->texture.loadFromFile("Textures//" + texture + ".png");
	this->body.setSize(this->size);
	this->body.setPosition(this->startPos);
	this->body.setOrigin(0.5f, 0.5f);
	this->body.setTexture(&this->texture);

	this->isStatic = true;

}

GameObject::GameObject() {



}

GameObject::~GameObject() {



}

sf::Vector2f GameObject::getPos(void) const{

	return this->body.getPosition();

}

sf::Vector2f GameObject::getSize(void) const{

	return this->size;

}

sf::Vector2f GameObject::getCenter(void) const{

	return this->center;

}

bool GameObject::getIsStatic(void) const {

	return this->isStatic;

}

sf::RectangleShape GameObject::getBody(void) const{

	return this->body;

}

void GameObject::updateCenter(void) {

	sf::Vector2f pos = this->body.getPosition();

	this->center = sf::Vector2f(pos.x + (this->size.x / 2.0f),
		pos.y + (this->size.y / 2.0f));

}

void GameObject::draw(sf::RenderWindow& window) {

	window.draw(this->body);

}
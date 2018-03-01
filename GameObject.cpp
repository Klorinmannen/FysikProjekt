#include"GameObject.h"

GameObject::GameObject(sf::Vector2f pos, sf::Vector2f size, std::string texture) {

	this->pos = pos;
	this->size = size;
	this->isStatic = true;
	this->color = color;
	this->arrayIndex = 0;

}

GameObject::GameObject() {



}

GameObject::~GameObject() {



}

sf::Vector2f GameObject::getPos(void) const{

	return this->pos;

}

sf::Vector2f GameObject::getSize(void) const{

	return this->size;

}

bool GameObject::getIsStatic(void) const{

	return this->isStatic;

}

sf::Color GameObject::getColor(void) const{

	return this->color;

}

void GameObject::setIndex(int index) {

	this->arrayIndex = index;

}

bool GameObject::checkCollision(sf::Vector2f b_pos)
{
	this->objectSprite.getGlobalBounds().contains(b_pos);
}

#pragma once

#include"SFML\Graphics.hpp"

class GameObject {

protected:

	sf::Vector2f pos;	//Bottom left of quad
	sf::Vector2f size;
	bool isStatic;
	sf::Color color;
	int arrayIndex;

public:

	GameObject(sf::Vector2f pos, sf::Vector2f size, sf::Color color);
	GameObject();
	~GameObject();

	//Get
	sf::Vector2f getPos(void) const;
	sf::Vector2f getSize(void) const;
	bool getIsStatic(void) const;
	sf::Color getColor(void) const;

	//Set
	void setIndex(int index);

};

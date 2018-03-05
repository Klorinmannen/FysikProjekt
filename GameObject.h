#pragma once

#include"SFML\Graphics.hpp"

class GameObject {

protected:

	sf::Vector2f startPos;
	sf::Vector2f size;
	sf::Vector2f center;

	sf::Texture texture;
	sf::RectangleShape body;

	bool isStatic;

public:

	GameObject(sf::Vector2f pos, sf::Vector2f size, std::string texture);
	GameObject();
	~GameObject();

	void draw(sf::RenderWindow& window);
	void updateCenter(void);

	//Get
	sf::Vector2f getPos(void) const;
	sf::Vector2f getSize(void) const;
	sf::Vector2f getCenter(void) const;
	bool getIsStatic(void) const;
	sf::RectangleShape getBody(void) const;

};

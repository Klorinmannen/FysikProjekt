#pragma once

#include"SFML\Graphics.hpp"

class GameObject : public sf::Drawable {

protected:
	sf::Texture objectTexture;
	sf::Sprite objectSprite;
	sf::Vector2f pos;	//Bottom left of quad
	sf::Vector2f size;
	bool isStatic;
	sf::Color color;
	int arrayIndex;

	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
public:

	GameObject(sf::Vector2f pos, sf::Vector2f size, std::string texture);
	GameObject();
	~GameObject();

	//Get
	sf::Vector2f getPos(void) const;
	sf::Vector2f getSize(void) const;
	bool getIsStatic(void) const;
	sf::Color getColor(void) const;

	//Set
	void setIndex(int index);
	bool checkCollision(sf::Vector2f b_pos);

};

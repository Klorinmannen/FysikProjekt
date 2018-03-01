#pragma once

#include"GameObject.h"

class PhysicsObject : public GameObject{
public:
	//struct to set attributes
	struct PhysAttributes
	{
		sf::Vector2f initialVelocity;
		sf::Vector2f initialVelocity;
		sf::Vector2f initialAcceleration;
		sf::Vector2f initialSpeed;

		float mass;
		float gravity;
		float airResistance;
	};

protected:
	sf::Vector2f initialVelocity;
	sf::Vector2f currentVelocity;
	sf::Vector2f currentAcceleration;
	sf::Vector2f currentSpeed;

	float mass;
	float gravity;
	float airResistance;


public:
	PhysicsObject();
	PhysicsObject(sf::Vector2f pos, sf::Vector2f size, std::string texture);
	~PhysicsObject();

};
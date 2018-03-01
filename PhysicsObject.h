#pragma once

#include"GameObject.h"

class PhysicsObject : public GameObject{

protected:

	sf::Vector2f vel;
	sf::Vector2f acc;

public:

	PhysicsObject();
	~PhysicsObject();

	void move();

	//Get
	

};
#pragma once

#include"GameObject.h"

class PhysicsObject : public GameObject{

protected:

	sf::Vector2f vel;
	sf::Vector2f acc;

public:

	PhysicsObject(sf::Vector2f pos, sf::Vector2f size, std::string texture);
	PhysicsObject();
	~PhysicsObject();

	void updateAcceleration();
	void updateVelocity(float dt);
	void move(void);
	void modifyAcceleration(sf::Vector2f modAcc);
	void setVelocity(sf::Vector2f modVel);

	void collision();

	//Get
	sf::Vector2f getVelocity(void) const;

};
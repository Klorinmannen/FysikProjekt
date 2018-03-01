#ifndef PROJECTILE_H
#define PROJECTILE_H
#include"PhysicsObject.h"

class Projectile : public PhysicsObject 
{
private:
	sf::Vector2i targetPos;


public:
	Projectile();
	~Projectile();

	void update(float dt);
	void move();

};
#endif // !PROJECTILE_H

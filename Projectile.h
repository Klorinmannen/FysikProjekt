#ifndef PROJECTILE_H
#define PROJECTILE_H
#include"PhysicsObject.h"

class Projectile : public PhysicsObject 
{
public:
	enum bulletType { marble, iron, gold };

private:
	sf::Vector2f targetPos;  //initial position aquired by the mouse.getPos() function

	bulletType currentType;

	void movementUpdate(float dt);
public:
	Projectile();
	Projectile(Projectile::bulletType new_type);
	~Projectile();

	void update(float dt); //updates bullets movement etc
	void setAttributes(PhysAttributes new_attributes); //struct to fillout physics attributes
	Projectile::bulletType getType();
	sf::Vector2f getPosition();
	void setTargetPos(sf::Vector2f in_pos);
};
#endif // !PROJECTILE_H

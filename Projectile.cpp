#include "Projectile.h"


Projectile::Projectile()
{
}

Projectile::Projectile(Projectile::bulletType new_type)
{
	this->currentType = new_type;
}

Projectile::~Projectile()
{
}

void Projectile::movementUpdate(float dt)
{
	//step method

}

void Projectile::update(float dt)
{

	this->movementUpdate(dt);
}

void Projectile::setAttributes(PhysAttributes new_attributes)
{
	//set all needed attributes
	this->currentAcceleration = new_attributes.initialAcceleration;
	//and more
}

Projectile::bulletType Projectile::getType()
{
	return this->currentType;
}

sf::Vector2f Projectile::getPosition()
{
	return this->pos;
}

void Projectile::setTargetPos(sf::Vector2f in_pos)
{
	this->targetPos = in_pos;
}

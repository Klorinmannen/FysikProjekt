#include "Player.h"
#include<iostream>


Player::Player()
{
	this->bullets.push_back(Projectile(Projectile::bulletType::marble));
	this->bullets.push_back(Projectile(Projectile::bulletType::iron));
	this->bullets.push_back(Projectile(Projectile::bulletType::gold));

	this->objectTexture.loadFromFile("string string string");
	this->objectSprite.setTexture(this->objectTexture);
}

Player::~Player()
{
}


void Player::errorMsg(Projectile::bulletType b_type)
{
	std::cout << "Error: wrong bulletType assigned. No such bulletType id exists: " + b_type << std::endl;
	system("PAUSE");
	exit(-1);
}

void Player::errorMsg(Player::direction in_dir)
{
	std::cout << "Error: wrong direction assigned. No such direction id exists: " + in_dir << std::endl;
	system("PAUSE");
	exit(-1);
}

void Player::setBulletValues(PhysAttributes n_attributes, Projectile::bulletType b_type)
{
	switch (b_type)
	{
	case Projectile::marble:
		this->bullets[0].setAttributes(n_attributes);
		break;
	case Projectile::iron:
		this->bullets[1].setAttributes(n_attributes);
		break;
	case Projectile::gold:
		this->bullets[2].setAttributes(n_attributes);
		break;
	default:
		this->errorMsg(b_type);
		break;
	}
}

void Player::onCollisionReset()
{
	this->hasTarget = false;
}

sf::Vector2f Player::getBulletPos()
{
	return this->currentProjectile.getPos();
}

void Player::update(float dt)
{
	if (this->hasTarget)
	{
		//update bullet movement and all that
		this->currentProjectile.update(dt);

	}
	//else just .. wait for bullets to fly
	
}

void Player::setTargetPos(sf::Vector2f in_pos)
{
	//indicates the start of projectile movement
	this->currentProjectile.setTargetPos(in_pos);
	this->hasTarget = true;
}

void Player::movePlayer(Player::direction in_dir, float dt)
{

	switch (in_dir)
	{
	case Player::up:
		this->pos += sf::Vector2f(0.0f, -this->moveSpeed) * dt;
		break;
	case Player::down:
		this->pos += sf::Vector2f(0.0f, this->moveSpeed) * dt;
		break;
	case Player::right:
		this->pos += sf::Vector2f(this->moveSpeed, 0.0f) * dt;
		break;
	case Player::left:
		this->pos += sf::Vector2f(-this->moveSpeed, 0.0f) * dt;
		break;
	default:
		break;
	}

}

void Player::setCurrentBullet(Projectile::bulletType b_type)
{
	//assigns currentProjectile with the projectile to use

	switch (b_type)
	{
	case Projectile::marble:
		this->currentProjectile = this->bullets[0];
		break;
	case Projectile::iron:
		this->currentProjectile = this->bullets[1];
		break;
	case Projectile::gold:
		this->currentProjectile = this->bullets[2];
		break;
	default:
		this->errorMsg(b_type);
		break;
	}
}


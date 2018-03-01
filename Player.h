#ifndef PLAYER_H
#define PLAYER_H
#include"Projectile.h"

class Player : public PhysicsObject
{
private:
	Projectile marbleBullet; //lightest
	Projectile ironBullet; //middelest
	Projectile goldBullet; //heaviest

	int stepSpeed = 10;

public:
	Player();
	~Player();

	void setTargetPos(sf::Vector2i in_vec);
	void moveLeft();
	void moveRight();
};
#endif // !PLAYER_H

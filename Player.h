#ifndef PLAYER_H
#define PLAYER_H
#include"Projectile.h"
#include<vector>
class Player : public PhysicsObject
{
public:
	enum direction { up, down, right, left };
	
private:
	std::vector<Projectile> bullets;
	Projectile currentProjectile;
	bool hasTarget = false;
	float moveSpeed = 20.0f;


	void errorMsg(Projectile::bulletType b_type);
	void errorMsg(Player::direction in_dir);
public:
	Player();
	~Player();
	void update(float dt);
	void setTargetPos(sf::Vector2f in_vec);
	void movePlayer(direction in_dir, float dt);
	void setCurrentBullet(Projectile::bulletType b_type);
	void setBulletValues(PhysAttributes new_attributes, Projectile::bulletType b_type);
	void onCollisionReset();
	sf::Vector2f getBulletPos();
};
#endif // !PLAYER_H

#include"PhysicsObject.h"

PhysicsObject::PhysicsObject(sf::Vector2f pos, sf::Vector2f size, std::string texture) : GameObject(pos, size, texture){

	//Set outline for all physics objects except the player
	if (texture != "Player") {

		this->body.setOutlineColor(sf::Color(226, 255, 229, 255));
		this->body.setOutlineThickness(2);

	}

	//Set center
	this->center = sf::Vector2f(this->startPos.x + (this->size.x / 2.0f),
		this->startPos.y - (this->size.y / 2.0f));

	//Set initial accerlaeration & velocity
	this->vel = sf::Vector2f(0.0f, 0.0f);
	this->acc = sf::Vector2f(0.0f, 0.0f);

	this->isStatic = false;

}

PhysicsObject::PhysicsObject() {



}

PhysicsObject::~PhysicsObject() {


	
}

void PhysicsObject::updateAcceleration() {

	//Gravity
	this->acc.y += 9.82;

	//Air resistance
	

}

void PhysicsObject::updateVelocity(float dt) {

	this->vel.x += (this->acc.x * dt);
	this->vel.y += (this->acc.y * dt);

}

void PhysicsObject::move(void) {

	this->body.move(this->vel);

}

void PhysicsObject::modifyAcceleration(sf::Vector2f modAcc) {

	this->acc.x += modAcc.x;
	this->acc.y += modAcc.y;

}

void PhysicsObject::setVelocity(sf::Vector2f modVel) {

	this->vel = modVel;

}

void PhysicsObject::collision() {



}

sf::Vector2f PhysicsObject::getVelocity(void) const{

	return this->vel;

}
#include"PhysicsObject.h"

PhysicsObject::PhysicsObject() {



}

PhysicsObject::~PhysicsObject() {


	
}

void PhysicsObject::move() {

	this->pos += this->vel;

}
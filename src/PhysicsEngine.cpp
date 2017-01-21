//
// Created by arnoul_r on 21/01/17.
//

#include <iostream>
#include "../include/PhysicsEngine.hh"

PhysicsEngine::PhysicsEngine(float xGravity, float yGravity) {
	b2Vec2 gravity(xGravity, yGravity);
	this->world = new b2World(gravity);
	this->refreshFrequency = 1.0f / 60.0f;
}

PhysicsEngine::~PhysicsEngine() {
	delete(this->world);
}


b2Body*                 PhysicsEngine::createRectangle(int x, int y, int w, int h, double deg, bool dyn)
{
	b2BodyDef           def;
	b2Body              *body;
	b2PolygonShape      shape;
	b2FixtureDef        fix;

	def.position.Set(x / SCALE, y / SCALE);
	def.angle = deg * 0.0174533;
	if (dyn)
		def.type = b2_dynamicBody;
	body = this->world->CreateBody(&def);
	shape.SetAsBox(w / 2 / SCALE, h / 2 / SCALE);
	fix.shape = &shape;
	fix.density = 1.0;
	body->CreateFixture(&fix);
	return body;
}



void                                PhysicsEngine::Step()
{
	this->world->Step(this->refreshFrequency, 5, 5);
}


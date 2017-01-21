//
// Created by arnoul_r on 21/01/17.
//

#include "PhysicsEngine.hh"

PhysicsEngine::PhysicsEngine(float xGravity, float yGravity) {
	this->world = new b2World(b2Vec2(xGravity, yGravity));
	this->refreshFrequency = 1 / 60;
}

PhysicsEngine::~PhysicsEngine() {
	delete(this->world);
}

b2Body*                 PhysicsEngine::createRectangle(int x, int y, int w, int h, bool dyn)
{
	b2BodyDef           def;
	b2Body              *body;
	b2PolygonShape      shape;
	b2FixtureDef        fix;

	def.position.Set(x, y);
	if (dyn)
		def.type = b2_dynamicBody;
	body = this->world->CreateBody(&def);
	shape.SetAsBox(w / 2, h / 2);
	fix.shape = &shape;
	fix.density = 1.0;
	body->CreateFixture(&fix);
	return body;
}

std::vector<b2Vec2>                 PhysicsEngine::getVertices(b2Body* body)
{
	std::vector<b2Vec2>        vector;

	for (int i = 0; i <4 ; i++)
		vector.push_back(((b2PolygonShape*)body->GetFixtureList()->GetShape())->GetVertex(i));
	return vector;
}


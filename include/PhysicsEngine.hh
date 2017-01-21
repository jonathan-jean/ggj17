//
// Created by arnoul_r on 21/01/17.
//

#ifndef GGJ17_PHYSICSENGINE_HH
#define GGJ17_PHYSICSENGINE_HH

static const float SCALE = 30.f;

#include <Box2D/Box2D.h>
#include <vector>

class PhysicsEngine {

public:
	b2World            *world;
	float              refreshFrequency;

public:
	PhysicsEngine(float, float);
	~PhysicsEngine();

public:
	b2Body*                     createRectangle(int, int, int, int, double, bool = true);
	void                        Step();

};


#endif //GGJ17_PHYSICSENGINE_HH

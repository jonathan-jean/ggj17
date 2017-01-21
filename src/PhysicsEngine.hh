//
// Created by arnoul_r on 21/01/17.
//

#ifndef GGJ17_PHYSICSENGINE_HH
#define GGJ17_PHYSICSENGINE_HH

#include <Box2D/Box2D.h>
#include <vector>

class PhysicsEngine {

private:
	b2World             *world;
	float               refreshFrequency;

public:
	PhysicsEngine(float, float);
	~PhysicsEngine();

public:
	b2Body*                     createRectangle(int, int, int, int, bool = true);
	static std::vector<b2Vec2>  getVertices(b2Body *);

};


#endif //GGJ17_PHYSICSENGINE_HH

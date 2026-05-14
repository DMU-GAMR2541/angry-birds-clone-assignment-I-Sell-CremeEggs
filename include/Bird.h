#pragma once
#include "DynamicObject.h"
#include "BirdTypes.h"

class Bird : public DynamicObject
{
private:
	BirdType type;
	bool isInFlight = false;
public:
	Bird(b2World& world, b2Vec2 position, BirdType type);
	void SetPosition(b2Vec2& position);
	void EnablePhysics(bool enabled);
	void Launch(b2Vec2& impulse);
	b2Body* GetBody();
	void SetInFlight(bool inFlight);
	bool IsInFlight();
};
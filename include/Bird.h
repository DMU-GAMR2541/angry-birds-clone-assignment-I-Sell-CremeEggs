#pragma once
#include "DynamicObject.h"
#include "BirdTypes.h"

class Bird : public DynamicObject
{
private:
	BirdType type;
public:
	Bird(b2World& world, b2Vec2 position, BirdType type);
};
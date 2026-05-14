#pragma once
#include "DynamicObject.h"
#include "PigTypes.h"

class Pig : public DynamicObject
{
private:
	PigType type;
	int health;
public:
	Pig(b2World& world, b2Vec2 position, PigType type);
	void TakeDamage(float damage);
	bool IsDead();
};
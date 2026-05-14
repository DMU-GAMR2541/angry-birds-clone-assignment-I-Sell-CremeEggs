#pragma once
#include "DynamicObject.h"
#include "StructureTypes.h"

class Structure : public DynamicObject
{
private:
	StructureType type;
	int health;
	bool isDestroyed = false;
public:
	Structure(b2World& world, b2Vec2 position, StructureType type);
	void TakeDamage(float damage);
	b2Body* GetBody();
	bool IsDestroyed();
};

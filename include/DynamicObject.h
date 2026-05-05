#pragma once
#include "GameObject.h"
class DynamicObject : GameObject
{
private:
	sf::Vector2f velocity;
public:
	DynamicObject() = default;

	~DynamicObject() = default;

	DynamicObject(GameObject, sf::Vector2f velocity)
	{
		this->velocity = velocity;
	}

	void Render(b2World world) override
	{
		
	}

};
#pragma once
#include "GameObject.h"
class DynamicObject : public GameObject
{
protected:
	b2BodyDef bodyDef;
	b2Body* body = nullptr;
public:
	DynamicObject()
	{

	}

	~DynamicObject() = default;

	void virtual CreateObject(b2World& world, b2Vec2 position){}
	void SetSprite(std::string textureLocation) override;
	void Update() override;
	void Render(sf::RenderWindow& window) override;
};
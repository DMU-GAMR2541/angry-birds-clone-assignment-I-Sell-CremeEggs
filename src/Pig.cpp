
#include "Pig.h"
#include "PigProfile.h"

Pig::Pig(b2World& world, b2Vec2 position, PigType type)
{
	this->type = type;
	PigProfile profile = pigProfiles[type];
	health = profile.health;

	bodyDef.type = b2_dynamicBody;
	bodyDef.position = position;

	body = world.CreateBody(&bodyDef);
	body->GetUserData().pointer = profile.pigID;

	b2CircleShape shape;
	shape.m_radius = profile.radius;

	b2FixtureDef fixture;
	fixture.shape = &shape;
	fixture.density = profile.density;

	body->CreateFixture(&fixture);

	SetSprite(profile.texturePath);

	sf::Vector2u textureSize = texture.getSize();
	sprite.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
	float desiredSize = shape.m_radius * 2.0f * scale;
	sprite.setScale(desiredSize / textureSize.x, desiredSize / textureSize.y);
};

void Pig::TakeDamage(float damage)
{
	health -= damage;
	if (health <= 0)
	{
		isDestroyed = true;
	}
}

b2Body* Pig::GetBody()
{
	return body;
}

bool Pig::IsDead()
{
	return isDestroyed;
}
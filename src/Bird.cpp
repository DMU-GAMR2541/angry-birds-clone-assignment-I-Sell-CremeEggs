#include "Bird.h"
#include "BirdProfile.h"

Bird::Bird(b2World& world, b2Vec2 position, BirdType type)
{
	this->type = type;
	BirdProfile profile = birdProfiles[type];

	bodyDef.type = b2_dynamicBody;
	bodyDef.position = position;

	body = world.CreateBody(&bodyDef);

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
}
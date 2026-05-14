#include "Bird.h"
#include "BirdProfile.h"

Bird::Bird(b2World& world, b2Vec2 position, BirdType type)
{
	this->type = type;
	BirdProfile profile = birdProfiles[type];

	bodyDef.type = b2_dynamicBody;
	bodyDef.position = position;

	body = world.CreateBody(&bodyDef);
	body->GetUserData().pointer = 100;

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

void Bird::SetPosition(b2Vec2& position)
{
	body->SetTransform(position, body->GetAngle());
}

void Bird::EnablePhysics(bool enabled)
{
	if (enabled)
	{
		body->SetGravityScale(1.0f);
		body->SetAwake(true);
	}
	else
	{
		body->SetLinearVelocity(b2Vec2_zero);
		body->SetAngularVelocity(0.0f);
		body->SetGravityScale(0.0f);
	}
}

void Bird::Launch(b2Vec2& impulse)
{
	EnablePhysics(true);
	body->ApplyLinearImpulseToCenter(impulse, true);
}

b2Body* Bird::GetBody()
{
	return body;
}

bool Bird::IsInFlight()
{
	return isInFlight;
}

void Bird::SetInFlight(bool isInFlight)
{
	this->isInFlight = isInFlight;
}
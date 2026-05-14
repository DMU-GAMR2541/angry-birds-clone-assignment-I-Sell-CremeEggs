#include "Structure.h"
#include "StructureProfile.h"

Structure::Structure(b2World& world, b2Vec2 position, StructureType type)
{
	this->type = type;
	StructureProfile profile = structureProfiles[type];
	health = profile.health;

	bodyDef.type = b2_dynamicBody;
	bodyDef.position = position;

	body = world.CreateBody(&bodyDef);
	body->GetUserData().pointer = profile.structID;

	b2PolygonShape shape;
	shape.SetAsBox(profile.height, profile.width);

	b2FixtureDef fixture;
	fixture.shape = &shape;
	fixture.density = profile.density;

	body->CreateFixture(&fixture);
	
	SetSprite(profile.texturePath);

	sf::Vector2u textureSize = texture.getSize();
	sprite.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
	float desiredHeight = profile.height * scale * 2.0f;
	float desiredWidth = profile.width * scale * 2.0f;
	sprite.setScale(desiredHeight / textureSize.x, desiredWidth / textureSize.y);
}

void Structure::TakeDamage(float damage)
{
	health -= damage;
	if (health <= 0)
	{
		isDestroyed = true;
	}
}

b2Body* Structure::GetBody()
{
	return body;
}

bool Structure::IsDestroyed()
{
	return isDestroyed;
}
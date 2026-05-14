#include "Slingshot.h"

Slingshot::Slingshot(b2World& world, b2Vec2 position, b2Vec2 anchorPoint, float height, float width)
{
	this->anchorPoint = anchorPoint;
	loadedBird = nullptr;
	dragging = false;
	maxStretch = 2.0f;
	launchPower = 16.0f;

	bodyDef.type = b2_kinematicBody;
	bodyDef.position = position;

	body = world.CreateBody(&bodyDef);

	b2PolygonShape shape;
	shape.SetAsBox(height, width);

	b2FixtureDef fixture;
	fixture.shape = &shape;
	
	body->CreateFixture(&fixture);
	body->SetEnabled(false);

	SetSprite("../assets/ang_birds/slingshot.png");

	sf::Vector2u textureSize = texture.getSize();
	sprite.setOrigin(textureSize.x / 2.0f, textureSize.y / 2.0f);
	float desiredHeight = height * scale * 2.0f;
	float desiredWidth = width * scale * 2.0f;
	sprite.setScale(desiredHeight / textureSize.x, desiredWidth / textureSize.y);
}

bool Slingshot::IsBirdLoaded()
{
	if (loadedBird != nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Slingshot::IsBirdInFlight()
{
	if (birdInFlight)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Slingshot::LoadBird(Bird* bird)
{
	loadedBird = bird;

	loadedBird->EnablePhysics(false);

	loadedBird->SetPosition(anchorPoint);
}

void Slingshot::BeginDrag()
{
	if (loadedBird)
	{
		dragging = true;
	}
}

void Slingshot::UpdateDrag(sf::Vector2f mousePosition)
{
	if (!dragging || !loadedBird)
	{
		return;
	}

	b2Vec2 mousePositionBox2D(mousePosition.x / scale, mousePosition.y / scale);
	b2Vec2 offset = mousePositionBox2D - anchorPoint;
	float length = offset.Length();
	if (length > maxStretch)
	{
		offset *= maxStretch / length;
	}
	b2Vec2 newPosition = anchorPoint + offset;

	loadedBird->SetPosition(newPosition);
}

void Slingshot::Release()
{
	if (!dragging || !loadedBird)
	{
		return;
	}
	dragging = false;
	birdInFlight = true;
	b2Vec2 birdPos = loadedBird->GetBody()->GetPosition();
	b2Vec2 launchVector = anchorPoint - birdPos;
	launchVector *= launchPower;

	loadedBird->Launch(launchVector);
	loadedBird = nullptr;
}
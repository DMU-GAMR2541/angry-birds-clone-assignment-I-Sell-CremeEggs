#pragma once
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
class GameObject
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	b2BodyDef bodyDef;
	b2Vec2 position;
protected:
	const float scale = 30.0f;
	const float PI = 3.1415927f;
public:
	GameObject() = default;

	~GameObject() = default;

	GameObject(b2BodyDef bodyDef, b2Vec2 position)
	{
		this->bodyDef = bodyDef;
		this->position = position;
	}

	void SetSprite(std::string textureLocation)
	{
		if (!texture.loadFromFile(textureLocation))
		{
			
		}
		sprite.setTexture(texture);
	}

	virtual void Render(b2World world)
	{
		bodyDef.position.Set(position.x, position.y);
		b2Body* body = world.CreateBody(&bodyDef);

		sprite.setPosition(body->GetPosition().x * scale, body->GetPosition().y * scale);
		sprite.setRotation(body->GetAngle() * (180.0f / PI));
	}
};

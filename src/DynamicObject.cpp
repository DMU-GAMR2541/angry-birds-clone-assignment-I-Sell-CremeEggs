#include "DynamicObject.h"

void DynamicObject::SetSprite(std::string textureLocation)
{
	if (!texture.loadFromFile(textureLocation))
	{
		std::cout << "Texture failed to load" << textureLocation << std::endl;
	}
	sprite.setTexture(texture);
}

void DynamicObject::Update()
{
	sprite.setPosition(body->GetPosition().x * scale, body->GetPosition().y * scale);
	sprite.setRotation(body->GetAngle() * (180.0f / PI));
}

void DynamicObject::Render(sf::RenderWindow& window)
{
	window.draw(sprite);
}

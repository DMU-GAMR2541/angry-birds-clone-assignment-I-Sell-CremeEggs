#include "DynamicObject.h"

void DynamicObject::SetSprite(std::string textureLocation)
{
	if (!texture.loadFromFile(textureLocation))
	{
		std::cout << "Texture failed to load" << textureLocation << std::endl;
	}
	sprite.setTexture(texture);
	std::cout << texture.getSize().x << ", " << texture.getSize().y << std::endl;
}

void DynamicObject::Update()
{
	std::cout << body->GetPosition().x * scale << ", " << body->GetPosition().y * scale << std::endl;
	sprite.setPosition(body->GetPosition().x * scale, body->GetPosition().y * scale);
	sprite.setRotation(body->GetAngle() * (180.0f / PI));
}

void DynamicObject::Render(sf::RenderWindow& window)
{
	window.draw(sprite);
}

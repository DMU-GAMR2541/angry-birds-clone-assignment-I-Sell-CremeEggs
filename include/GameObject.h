#pragma once
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <iostream>
class GameObject
{
protected:
	sf::Texture texture;
	sf::Sprite sprite;
	const float scale = 30.0f;
	const float PI = 3.1415927f;
public:
	GameObject() = default;

	virtual ~GameObject() = default;

	virtual void SetSprite(std::string textureLocation) = 0;

	virtual void Update() = 0;

	virtual void Render(sf::RenderWindow& window) = 0;

};

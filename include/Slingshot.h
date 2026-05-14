#pragma once
#include <string>
#include "Bird.h"

class Slingshot : public DynamicObject
{
private:
	enum class State
	{
		Idle,
		Loaded,
		Dragging,
		Fired
	};

	State state;
	Bird* loadedBird;
	b2Vec2 anchorPoint;
	bool dragging;
	float maxStretch;
	float launchPower;

public:
	Slingshot(b2World& world, b2Vec2 position, b2Vec2 anchorPoint, float height, float width);
	Bird* GetLoadedBird();
	bool IsBirdLoaded();
	void LoadBird(Bird* bird);
	void BeginDrag();
	void UpdateDrag(sf::Vector2f mousePosition);
	void Release();

};
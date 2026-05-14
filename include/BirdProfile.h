#pragma once

#include <string>
#include <map>
#include "BirdTypes.h"

struct BirdProfile
{
	float radius;
	float density;
	float friction;
	float restitution;
	std::string texturePath;
};

static std::map<BirdType, BirdProfile> birdProfiles =
{
	{
		BirdType::Red,
		{
			1.0f,
			0.8f,
			0.2f,
			0.3f,
			"../assets/ang_birds/RedBird.png"
		}
	},

	{
		BirdType::Blue,
		{
			1.0f,
			0.8f,
			0.2f,
			0.3f,
			"../assets/ang_birds/BlueBird.png"
		}
	},

	{
		BirdType::Yellow,
		{
			1.0f,
			0.8f,
			0.2f,
			0.3f,
			"../assets/ang_birds/YellowBird.png"
		}
	},

	{
		BirdType::Black,
		{
			1.0f,
			0.8f,
			0.2f,
			0.3f,
			"../assets/ang_birds/BombBird.png"
		}
	}
};
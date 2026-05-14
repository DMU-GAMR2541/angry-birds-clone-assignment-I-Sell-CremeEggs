#pragma once

#include <string>
#include <map>
#include "PigTypes.h"

struct PigProfile
{
	int pigID;
	int health;
	float radius;
	float density;
	std::string texturePath;
};

static std::map<PigType, PigProfile> pigProfiles =
{
	{
		PigType::SmallPig,
		{
			3,
			50,
			0.8f,
			1.0f,
			"../assets/ang_birds/SmallPig.png"
		}
	},

	{
		PigType::MediumPig,
		{
			4,
			100,
			1.2f,
			1.5f,
			"../assets/ang_birds/mediumPig.png"
		}
	},

	{
		PigType::LargePig,
		{
			5,
			150,
			1.6f,
			2.0f,
			"../assets/ang_birds/largePig.png"
		}
	},
};
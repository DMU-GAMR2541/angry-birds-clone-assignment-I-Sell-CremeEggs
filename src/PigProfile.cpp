#pragma once
#include <map>
#include "PigTypes.h"
#include "PigProfile.h"

static std::map<PigType, PigProfile> pigProfiles =
{
	{
		PigType::SmallPig,
		{
			50,
			0.4f,
			1.0f,
			"Assets/smallPig.png"
		}
	},

	{
		PigType::MediumPig,
		{
			100,
			0.6f,
			1.5f,
			"Assets/mediumPig.png"
		}
	},

	{
		PigType::LargePig,
		{
			150,
			0.8f,
			2.0f,
			"Assets/largePig.png"
		}
	},
};
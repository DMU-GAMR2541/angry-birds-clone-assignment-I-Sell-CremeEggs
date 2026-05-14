#pragma once

#include <string>
#include <map>
#include "StructureTypes.h"

struct StructureProfile
{
	int health;
	float height;
	float width;
	float density;
	std::string texturePath;
};

static std::map<StructureType, StructureProfile> structureProfiles =
{
	{
		StructureType::WoodPillar,
		{
			50,
			1.0f,
			0.2f,
			0.5f,
			"../assets/ang_birds/WoodPillar.png"
		}
	},

	{
		StructureType::GlassPillar,
		{
			25,
			1.0f,
			0.2f,
			0.3f,
			"../assets/ang_birds/GlassPillar.png"
		}
	},

	{
		StructureType::StonePillar,
		{
			100,
			1.0f,
			0.2f,
			0.8f,
			"../assets/ang_birds/StonePillar.png"
		}
	},

	{
		StructureType::WoodBlock,
		{
			50,
			0.8f,
			0.8f,
			0.5f,
			"../assets/ang_birds/WoodBlock.png"
		}
	},

	{
		StructureType::GlassBlock,
		{
			25,
			0.8f,
			0.8f,
			0.3f,
			"../assets/ang_birds/GlassBlock.png"
		}
	},

	{
		StructureType::StoneBlock,
		{
			100,
			0.8f,
			0.8f,
			0.8f,
			"../assets/ang_birds/StoneBlock.png"
		}
	},
};
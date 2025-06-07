#pragma once

#include "Seed.h"
#include "Enum/SeedType.h"
#include <memory>
#include <map>

class SeedFactory {
public:
	static std::shared_ptr<Seed> createSeed(SeedType type);
	static std::string SeedTypeToString(SeedType type) {
		switch (type) {
			case SeedType::WHEAT: return "Wheat Seed";
			case SeedType::CORN: return "Corn Seed";
			case SeedType::TOMATO: return "Tomato Seed";
			case SeedType::SUNFLOWER: return "Sunflower Seed";
			case SeedType::PUMPKIN: return "Pumpkin Seed";
			case SeedType::CARROT: return "Carrot Seed";
			case SeedType::STRAWBERRY: return "Strawberry Seed";
			case SeedType::COTON: return "Cotton Seed";
			case SeedType::COCOA: return "Cocoa Bean";
			case SeedType::GOJI_BERRY: return "Goji Berry Seed";
			case SeedType::CARNIVOROUS_PLANT: return "Carnivorous Plant Seed";
			case SeedType::ORCHID: return "Rare Orchid Seed";
			case SeedType::MUSHROOM: return "Luminescent Mushroom Seed";
			case SeedType::BAMBOO: return "Sacred Bamboo Seed";
			case SeedType::PALM_TREE: return "Millennium Palm Tree Seed";
			case SeedType::FLOWER_LOTUS: return "Celestial Lotus Seed";
			case SeedType::ROSE: return "Eternal Rose Seed";
			case SeedType::HEMP: return "Evil Hemp Seed";
			case SeedType::TREE: return "Tree";
			default: return "Unknown";
		}
	}
	static const std::map<SeedType, int>& getAllSeedWeights();
};

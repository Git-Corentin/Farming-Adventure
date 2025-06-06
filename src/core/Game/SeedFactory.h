#pragma once

#include "Seed.h"
#include "Enum/SeedType.h"
#include <memory>

class SeedFactory {
public:
	static std::shared_ptr<Seed> createSeed(SeedType type);
	static inline std::string SeedTypeToString(SeedType type) {
		switch (type) {
			case SeedType::WHEAT: return "Wheat";
			case SeedType::CORN: return "Corn";
			case SeedType::PUMPKIN: return "Pumpkin";
			case SeedType::COCOA: return "Cocoa";
			case SeedType::TOMATO: return "Tomato";
			case SeedType::SUNFLOWER: return "Sunflower";
			case SeedType::COTON: return "Cotton";
			case SeedType::GOJI_BERRY: return "Goji Berry";
			case SeedType::PALM_TREE: return "Palm Tree";
			case SeedType::CARROT: return "Carrot";
			case SeedType::STRAWBERRY: return "Strawberry";
			case SeedType::FLOWER_LOTUS: return "Flower Lotus";
			case SeedType::HEMP: return "Hemp";
			case SeedType::ROSE: return "Rose";
			case SeedType::TREE: return "Tree";
			case SeedType::MUSHROOM: return "Mushroom";
			case SeedType::CARNIVOROUS_PLANT: return "Carnivorous Plant";
			case SeedType::BAMBOO: return "Bamboo";
			case SeedType::ORCHID: return "Orchid";

			default: return "Unknown";
		}
	}
};

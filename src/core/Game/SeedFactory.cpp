
#include "Seed.h"
#include "SeedFactory.h"
#include "Enum/SeedType.h"
#include <memory>


std::shared_ptr<Seed> SeedFactory::createSeed(SeedType type) {
	int growBase = 0;
	int moneyBase = 0;
	switch (type) {
		case SeedType::WHEAT: return std::make_shared<Seed>(SeedTypeToString(SeedType::WHEAT), 5+growBase, 10+moneyBase);
		case SeedType::CORN: return std::make_shared<Seed>(SeedTypeToString(SeedType::CORN), 6+growBase, 12+moneyBase);
		case SeedType::TOMATO: return std::make_shared<Seed>(SeedTypeToString(SeedType::TOMATO), 7+growBase, 15+moneyBase);
		case SeedType::SUNFLOWER: return std::make_shared<Seed>(SeedTypeToString(SeedType::SUNFLOWER), 8+growBase, 18+moneyBase);
		case SeedType::PUMPKIN: return std::make_shared<Seed>(SeedTypeToString(SeedType::PUMPKIN), 9+growBase, 20+moneyBase);
		case SeedType::CARROT: return std::make_shared<Seed>(SeedTypeToString(SeedType::CARROT), 10+growBase, 23+moneyBase);
		case SeedType::STRAWBERRY: return std::make_shared<Seed>(SeedTypeToString(SeedType::STRAWBERRY), 11+growBase, 25+moneyBase);
		case SeedType::COTON: return std::make_shared<Seed>(SeedTypeToString(SeedType::COTON), 12+growBase, 28+moneyBase);
		case SeedType::COCOA: return std::make_shared<Seed>(SeedTypeToString(SeedType::COCOA), 15+growBase, 35+moneyBase);
		case SeedType::GOJI_BERRY: return std::make_shared<Seed>(SeedTypeToString(SeedType::GOJI_BERRY), 18+growBase, 40+moneyBase);
		case SeedType::CARNIVOROUS_PLANT: return std::make_shared<Seed>(SeedTypeToString(SeedType::CARNIVOROUS_PLANT), 30+growBase, 70+moneyBase);
		case SeedType::ORCHID: return std::make_shared<Seed>(SeedTypeToString(SeedType::ORCHID), 35+growBase, 80+moneyBase);
		case SeedType::MUSHROOM: return std::make_shared<Seed>(SeedTypeToString(SeedType::MUSHROOM), 50+growBase, 120+moneyBase);
		case SeedType::BAMBOO: return std::make_shared<Seed>(SeedTypeToString(SeedType::BAMBOO), 60+growBase, 150+moneyBase);
		case SeedType::PALM_TREE: return std::make_shared<Seed>(SeedTypeToString(SeedType::PALM_TREE), 75+growBase, 200+moneyBase);
		case SeedType::FLOWER_LOTUS: return std::make_shared<Seed>(SeedTypeToString(SeedType::FLOWER_LOTUS), 100+growBase, 300+moneyBase);
		case SeedType::ROSE: return std::make_shared<Seed>(SeedTypeToString(SeedType::ROSE), 120+growBase, 400+moneyBase);
		case SeedType::HEMP: return std::make_shared<Seed>(SeedTypeToString(SeedType::HEMP), 110+growBase, 350+moneyBase);
		case SeedType::TREE: return std::make_shared<Seed>(SeedTypeToString(SeedType::TREE), 150+growBase, 500+moneyBase);
		default: return std::make_shared<Seed>(SeedTypeToString(SeedType::WHEAT), 5+growBase, 10+moneyBase); // Default case
	}

};

const std::map<SeedType, int>& SeedFactory::getAllSeedWeights() { //Map des poids nécessaire pour le coffre
	static const std::map<SeedType, int> seedWeights = {
		{SeedType::CORN, 500},
		{SeedType::TOMATO, 460},
		{SeedType::SUNFLOWER, 440},
		{SeedType::PUMPKIN, 420},
		{SeedType::CARROT, 400},
		{SeedType::STRAWBERRY, 380},
		{SeedType::COTON, 360},
		{SeedType::COCOA, 250},
		{SeedType::GOJI_BERRY, 200},
		{SeedType::CARNIVOROUS_PLANT, 150},
		{SeedType::ORCHID, 120},
		{SeedType::BAMBOO, 100},
		{SeedType::PALM_TREE, 80},
		{SeedType::FLOWER_LOTUS, 60},
		{SeedType::MUSHROOM, 40},
		{SeedType::ROSE, 30},
		{SeedType::HEMP, 20},
		{SeedType::TREE, 10}
	};
	return seedWeights;
}



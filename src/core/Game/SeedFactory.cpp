
#include "Seed.h"
#include "SeedFactory.h"
#include "Enum/SeedType.h"
#include <memory>


std::shared_ptr<Seed> SeedFactory::createSeed(SeedType type) {
	int growBase = 5;
	int moneyBase = 50;
	switch (type) {
		case SeedType::WHEAT: return std::make_shared<Seed>("Wheat", 5+growBase, 50+moneyBase);
		case SeedType::CORN: return std::make_shared<Seed>("Corn", 6+growBase, 55+moneyBase);
		case SeedType::PUMPKIN: return std::make_shared<Seed>("Pumpkin", 8+growBase, 70+moneyBase);
		case SeedType::COCOA: return std::make_shared<Seed>("Cocoa", 4+growBase, 40+moneyBase);
		case SeedType::TOMATO: return std::make_shared<Seed>("Tomato", 10+growBase, 60+moneyBase);
		case SeedType::SUNFLOWER: return std::make_shared<Seed>("Sunflower", 7+growBase, 65+moneyBase);
		case SeedType::COTON: return std::make_shared<Seed>("Cotton", 9+growBase, 75+moneyBase);
		case SeedType::GOJI_BERRY: return std::make_shared<Seed>("Goji Berry", 12+growBase, 80+moneyBase);
		case SeedType::PALM_TREE: return std::make_shared<Seed>("Palm Tree", 15+growBase, 100+moneyBase);
		case SeedType::CARROT: return std::make_shared<Seed>("Carrot", 3+growBase, 30+moneyBase);
		case SeedType::STRAWBERRY: return std::make_shared<Seed>("Strawberry", 11+growBase, 85+moneyBase);
		case SeedType::FLOWER_LOTUS: return std::make_shared<Seed>("Flower Lotus", 14+growBase, 90+moneyBase);
		case SeedType::HEMP: return std::make_shared<Seed>("Hemp", 13+growBase, 95+moneyBase);
		case SeedType::ROSE: return std::make_shared<Seed>("Rose", 16+growBase, 110+moneyBase);
		case SeedType::TREE: return std::make_shared<Seed>("Tree", 18+growBase, 115+moneyBase);
		case SeedType::MUSHROOM: return std::make_shared<Seed>("Mushroom", 2+growBase, 20+moneyBase);
		case SeedType::CARNIVOROUS_PLANT: return std::make_shared<Seed>("Carnivorous Plant", 17+growBase, 130+moneyBase);
		case SeedType::BAMBOO: return std::make_shared<Seed>("Bamboo", 19+growBase, 105+moneyBase);
		case SeedType::ORCHID: return std::make_shared<Seed>("Orchid", 20+growBase, 120+moneyBase);
		default: return std::make_shared<Seed>("Wheat", 5+growBase, 50+moneyBase); // Default case
	}

};





#include "Chest.h"
#include "Enum/SeedType.h"
#include "Game/SeedFactory.h"
#include <random>
#include <vector>
#include <map>

#include "Game/Game.h"
#include <iostream>


SeedChest::SeedChest() {
	cost = 500;
}

UtilityChest::UtilityChest() {
	cost = 150;
}

void SeedChest::open(Game& game) {

	if (game.getMoney() < cost) {
		std::cout << "Pas assez d'argent pour ouvrir le coffre (" << cost << " requis)\n";
		return;
	}

	game.removeMoney(cost);

	std::map<SeedType, int> seedWeights = {
		{SeedType::CORN, 15},
		{SeedType::PUMPKIN, 10},
		{SeedType::COCOA, 12},
		{SeedType::TOMATO, 15},
		{SeedType::SUNFLOWER, 12},
		{SeedType::COTON, 10},
		{SeedType::GOJI_BERRY, 5},
		{SeedType::PALM_TREE, 4},
		{SeedType::CARROT, 20},
		{SeedType::STRAWBERRY, 7},
		{SeedType::FLOWER_LOTUS, 5},
		{SeedType::HEMP, 6},
		{SeedType::ROSE, 3},
		{SeedType::TREE, 2},
		{SeedType::MUSHROOM, 15},
		{SeedType::CARNIVOROUS_PLANT, 1},
		{SeedType::BAMBOO, 8},
		{SeedType::ORCHID, 2}
	};

	std::random_device rd;
	std::mt19937 gen(rd());

	// Déterminer combien de graines seront données (entre 0 et 3)
	std::uniform_int_distribution<> seedCountDist(0, 3);
	int numSeeds = seedCountDist(gen);

	std::vector<SeedType> types;
	std::vector<int> weights;
	for (const auto& [type, weight] : seedWeights) {
		types.push_back(type);
		weights.push_back(weight);
	}

	std::discrete_distribution<> dist(weights.begin(), weights.end());

	std::cout << "Ouverture du coffre à graines..." << std::endl;
	for (int i = 0; i < numSeeds; ++i) {
		SeedType selected = types[dist(gen)];
		game.getSeedReservoir().addSeed(selected, 1);
		std::cout << " → Obtenu : " << SeedFactory::SeedTypeToString(selected) << "\n";
	}

	if (numSeeds == 0) {
		std::cout << " → Le coffre était vide cette fois-ci ! Pas de chance.\n";
	}
}

void UtilityChest::open(Game& game) {
	// À implémenter plus tard : effets, bonus, etc.
}
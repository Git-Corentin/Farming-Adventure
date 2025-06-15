
#include "Chest.h"
#include "Enum/SeedType.h"
#include "Game/SeedFactory.h"
#include <random>
#include <vector>
#include <map>

#include "Game/Game.h"
#include <iostream>


SeedChest::SeedChest() {
	cost = 40;
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

	const std::map<SeedType, int>& seedWeights = SeedFactory::getAllSeedWeights();

	std::random_device rd;
	std::mt19937 gen(rd());

	// Déterminer combien de graines seront données (entre 0 et 3)
	std::uniform_int_distribution<> seedCountDist(0, 3);
	int numSeeds = seedCountDist(gen);

	std::vector<SeedType> types;
	std::vector<int> weights;
	bool pesticide = game.isPesticideActive();

	for (const auto& [type, baseWeight] : seedWeights) {
		int weight = baseWeight;

		if (pesticide && weight <= 250) {
			// Augmenter artificiellement le poids des graines rares (poids faibles)
			weight *= 10; // ou *3 pour un effet plus fort
		}
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
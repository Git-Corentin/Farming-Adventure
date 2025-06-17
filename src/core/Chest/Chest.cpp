
#include "Chest.h"
#include "Enum/SeedType.h"
#include "Game/SeedFactory.h"
#include <random>
#include <vector>
#include <map>
#include "Effect/Utility.h"  // Pour les effets utilitaires
#include "Effect/Malus.h" // Pour les effets de malus

#include "Game/Game.h"
#include <iostream>


SeedChest::SeedChest() {
	cost = 40;
}

UtilityChest::UtilityChest() {
	cost = 60;
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
	if (game.getMoney() < cost) {
		std::cout << "Pas assez d'argent pour ouvrir le coffre (" << cost << " requis)\n";
		return;
	}

	game.removeMoney(cost);

	std::random_device rd;
	std::mt19937 gen(rd());

	static const std::vector<std::pair<std::string, int>> effectWeights = {
		{"Fertilizer", 400},
		{"Harvester", 300},
		{"Pesticide", 250},
		{"CleaningRobot", 150},
		{"EconomicCrisis", 100},
		{"GMO", 80},
		{"Storm", 150},
		{"Frost", 200},
		{"Thief", 250},
		{"Expiration", 75}
	};

	std::vector<std::string> effectNames;
	std::vector<int> weights;

	for (const auto& [name, weight] : effectWeights) {
		effectNames.push_back(name);
		weights.push_back(weight);

	}

	std::discrete_distribution<> dist(weights.begin(), weights.end());

	std::string selected = effectNames[dist(gen)];

	std::unique_ptr<Effect> effect;
	sf::Time duration = sf::seconds(20);  // Par défaut

	if (selected == "Fertilizer") {
		effect = std::make_unique<Fertilizer>();
	} else if (selected == "Harvester") {
		effect = std::make_unique<Harvester>();
	} else if (selected == "Pesticide") {
		effect = std::make_unique<Pesticide>();
	} else if (selected == "CleaningRobot") {
		effect = std::make_unique<CleaningRobot>();
		duration = sf::seconds(0);  // Instantané
	} else if (selected == "EconomicCrisis") {
		effect = std::make_unique<EconomicCrisis>();
	} else if (selected == "GMO") {
		effect = std::make_unique<GMO>();
	} else if (selected == "Storm") {
		effect = std::make_unique<Storm>();
		duration = sf::seconds(0);  // Instantané
	} else if (selected == "Frost") {
		effect = std::make_unique<Frost>();
	} else if (selected == "Thief") {
		effect = std::make_unique<Thief>();
		duration = sf::seconds(0);  // Instantané
	} else if (selected == "Expiration") {
		effect = std::make_unique<Expiration>();
		duration = sf::seconds(0);  // Instantané
	}

	if (effect) {
		game.addActiveEffect(std::move(effect), duration);
		std::cout << " → Obtenu : " << selected << "\n";
	}
}


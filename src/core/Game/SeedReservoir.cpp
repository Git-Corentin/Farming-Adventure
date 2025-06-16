//
// Created by corentin on 03/06/25.
//

#include "SeedReservoir.h"

bool SeedReservoir::isWheat(SeedType type) {
	return type == SeedType::WHEAT;
}

void SeedReservoir::removeSeed(SeedType type, int quantity) {
	if (!isWheat(type)) {
		seeds[type] -= quantity;
		if (seeds[type] <= 0) {
			seeds[type] = 0;
			if (selectedSeedType == type) {
				selectedSeedType = SeedType::WHEAT;
			}
		}
	}
}

int SeedReservoir::getSeedQuantity(SeedType type) const {
	if (isWheat(type)) {
		return 0; // Wheat is not stored
	}
	auto it = seeds.find(type);
	if (it != seeds.end()) {
		return it->second;
	}
	return 0;
}

void SeedReservoir::addSeed(SeedType type, int quantity) {
	if (isWheat(type)) {
		return; // Wheat cannot be added to the reservoir
	}
	seeds[type] += quantity;
}

void SeedReservoir::setSelectedSeed(SeedType type) {
	if (isWheat(type) || seeds[type] > 0) {
		selectedSeedType = type;
	}
}

SeedType SeedReservoir::getSelectedSeed() const {
	return selectedSeedType;
}

void SeedReservoir::removeRandomSeeds(int quantity) {
	std::vector<SeedType> availableSeeds;
	for (const auto& [type, qty] : seeds) {
		if (qty > 0 && !isWheat(type)) {
			availableSeeds.push_back(type);
		}
	}
	if (availableSeeds.empty()) {
		std::cout << "No seeds to remove.\n";
		return; // No seeds in storage
	}

	std::random_device rd;
	std::mt19937 gen(rd());
	
	for (int i = 0; i < quantity && !availableSeeds.empty(); ++i) {
		std::uniform_int_distribution<> dist(0, availableSeeds.size() - 1);
		int index = dist(gen);
		SeedType type = availableSeeds[index];
		removeSeed(type, 1);
		availableSeeds.erase(availableSeeds.begin() + index);
		std::cout << "Removed a " << SeedFactory::SeedTypeToString(type) << " from the reservoir.\n";
	}

}

void SeedReservoir::removeAllSeeds() {
	seeds.clear();
	selectedSeedType = SeedType::WHEAT; // Reset to wheat
	std::cout << "Everything was lost...\n";
}
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
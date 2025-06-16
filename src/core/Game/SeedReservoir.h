#pragma once


#include <map>
#include <random>
#include <iostream>

#include "Enum/SeedType.h"
#include "SeedFactory.h"


class SeedReservoir {
private:
	std::map<SeedType, int> seeds;
	SeedType selectedSeedType;

public:
	int getSeedQuantity(SeedType type) const;
	void addSeed(SeedType type, int quantity);
	void removeSeed(SeedType type, int quantity);
	void removeRandomSeeds(int maxQuantity);
	void setSelectedSeed(SeedType type);
	SeedType getSelectedSeed() const;

	static bool isWheat(SeedType type);
};

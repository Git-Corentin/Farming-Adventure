#pragma once


#include <map>

#include "Enum/SeedType.h"


class SeedReservoir {
private:
	std::map<SeedType, int> seeds;
	SeedType selectedSeedType;

public:
	int getSeedQuantity(SeedType type) const;
	void addSeed(SeedType type, int quantity);
	void removeSeed(SeedType type, int quantity);
	void setSelectedSeed(SeedType type);
	SeedType getSelectedSeed() const;
	SeedType getRandomNonWheatSeed() const;
};

#pragma once

#include "Seed.h"
#include "Enum/SeedType.h"
#include <memory>

class SeedFactory {
public:
	static std::shared_ptr<Seed> createSeed(SeedType type);
};

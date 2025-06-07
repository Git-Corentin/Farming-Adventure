
#include "Seed.h"

void Seed::applyGrowthModifier(int modifier) {
	currentClicksToGrow += modifier;
	if (currentClicksToGrow < 0) currentClicksToGrow = 0;
}

void Seed::resetClicks() {
		currentClicksToGrow = clicksToGrowBase;
}


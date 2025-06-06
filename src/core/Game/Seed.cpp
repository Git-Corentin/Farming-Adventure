
#include "Seed.h"

void Seed::applyGrowthModifier(int modifier) {
	currentClicksToGrow += modifier;
	if (currentClicksToGrow < 0) currentClicksToGrow = 0;
}

int Seed::getClicksToGrow() const {
	return currentClicksToGrow;
}

int Seed::getMoneyRaised() const {
	return moneyRaised;
}

void Seed::resetClicks() {
		currentClicksToGrow = clicksToGrowBase;
}


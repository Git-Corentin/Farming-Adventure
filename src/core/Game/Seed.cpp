#include "Seed.h"

Seed::Seed(std::string name, int clicksBase, int moneyBase)
	: name(std::move(name)),
	  clicksToGrowBase(clicksBase),
	  effectiveClicksToGrow(clicksBase),
	  currentClicksDone(0),
	  moneyBase(moneyBase),
	  moneyFinal(moneyBase)
{}

void Seed::applyMultipliers(float growthMultiplier, float rewardMultiplier) {
	effectiveClicksToGrow = std::max(1, static_cast<int>(clicksToGrowBase * growthMultiplier));
	moneyFinal = std::max(0, static_cast<int>(moneyBase * rewardMultiplier));
	resetClicks();
}

void Seed::resetClicks() {
	currentClicksDone = 0;
}

void Seed::incrementClicks() {
	++currentClicksDone;
}

bool Seed::isGrown() const {
	return currentClicksDone >= effectiveClicksToGrow;
}

int Seed::getClicksToGrow() const {
	return effectiveClicksToGrow;
}

int Seed::getCurrentClicksDone() const {
	return currentClicksDone;
}

int Seed::getMoneyRaised() const {
	return moneyFinal;
}

std::string Seed::getName() const {
	return name;
}

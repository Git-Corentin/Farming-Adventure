#pragma once

#include <string>
class Seed {
protected:
	std::string name;
	int clicksToGrowBase;
	int moneyRaised;
	int currentClicksToGrow;

public:
	Seed(const std::string& name, int grow, int money)
		: name(name), clicksToGrowBase(grow), moneyRaised(money), currentClicksToGrow(grow) {}
	void applyGrowthModifier(int modifier);

	int getClicksToGrow() const { return currentClicksToGrow; }
	int getMoneyRaised() const { return moneyRaised; }
	void resetClicks();

	std::string getName() const { return name; }
};


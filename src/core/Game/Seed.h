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
	int getClicksToGrow() const;
	int getMoneyRaised() const;
	void resetClicks();

	std::string getName() const { return name; }
};


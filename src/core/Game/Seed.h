#pragma once
#include <string>

class Seed {
public:
	Seed(std::string name, int clicksBase, int moneyBase);

	void applyMultipliers(float growthMultiplier, float rewardMultiplier);
	void resetClicks();
	void incrementClicks();

	bool isGrown() const;

	int getClicksToGrow() const; // effective
	int getCurrentClicksDone() const;

	int getMoneyRaised() const;
	std::string getName() const;

protected:
	std::string name;

	int clicksToGrowBase;
	int effectiveClicksToGrow;
	int currentClicksDone;

	int moneyBase;
	int moneyFinal;
};

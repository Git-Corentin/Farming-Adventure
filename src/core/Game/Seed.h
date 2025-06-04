#pragma once

#include <string>
class Seed {
protected:
	std::string name;
	int clicksToGrowBase;
	int moneyRaised;
	int currentClicksToGrow;

public:
	virtual ~Seed() = default;
	void applyGrowthModifier(int modifier);
	int getClicksToGrow() const;
	int getMoneyRaised() const;
	void resetClicks();

	std::string getName() const {
		return name;
	}
};

class WheatSeed : public Seed {
public:
	WheatSeed();
};

class RareSeed : public Seed {
public:
	RareSeed(const std::string& name, int grow, int money);
};

#pragma once

#include <string>
class Seed {
protected:
	std::string name;
	int clicksToGrowBase;
	int moneyPerClickBase;
	int currentClicksToGrow;

public:
	virtual ~Seed() = default;
	void applyGrowthModifier(int modifier);
	int getClicksToGrow() const;
	int getMoneyPerClick() const;
	void resetClicks();
};

class WheatSeed : public Seed {
public:
	WheatSeed();
};

class RareSeed : public Seed {
public:
	RareSeed(const std::string& name, int grow, int money);
};

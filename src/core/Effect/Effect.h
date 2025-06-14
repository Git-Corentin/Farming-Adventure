#pragma once
#include <string>

#include "EffectInterface.h"

class Game;

class Effect : public EffectInterface {
protected:
	std::string name;
	int duration; // 0 = permanent or instant

public:
	virtual ~Effect() = default;
	virtual void applyEffect(Game& game) = 0;
	virtual void removeEffect(Game& game) {} // Optional

	float getGrowthMultiplier() const override;
	float getRewardMultiplier() const override;

	virtual std::string getName() const { return name; }
};

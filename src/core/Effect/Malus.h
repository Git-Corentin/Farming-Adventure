#pragma once
#include "Effect.h"

class Storm : public Effect {
public:
	Storm();
	void applyEffect(Game& game) override;
};

class Frost : public Effect {
public:
	explicit Frost(float gmultiplier = 1.5f, float rmultiplier = 0.5);
	void applyEffect(Game& game) override;
	void removeEffect(Game& game) override;
	float getGrowthMultiplier() const override { return growthMultiplier; }
	float getRewardMultiplier() const override { return rewardMultiplier; }
private:
	float growthMultiplier;
	float rewardMultiplier;
};

class Thief : public Effect {
public:
	Thief();
	void applyEffect(Game& game) override;
};

class Expiration : public Effect {
public:
	Expiration();
	void applyEffect(Game& game) override;
};

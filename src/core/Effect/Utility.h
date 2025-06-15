#pragma once
#include "Effect.h"

class Pesticide : public Effect {
public:
	Pesticide();
	void applyEffect(Game& game) override;
	void removeEffect(Game& game) override;
};

class Fertilizer : public Effect {
public:
	explicit Fertilizer(float multiplier = 0.7f);
	void applyEffect(Game& game) override;
	void removeEffect(Game& game) override;
	float getGrowthMultiplier() const override { return growthMultiplier; }
private:
	float growthMultiplier;
};

class Harvester : public Effect {
public:
	Harvester();
	void applyEffect(Game& game) override;
	void removeEffect(Game& game) override;
};

class CleaningRobot : public Effect {
public:
	CleaningRobot();
	void applyEffect(Game& game) override;
};

class GMO : public Effect {
public:
	explicit GMO(float growthMultiplier = 0.8f, float rewardMultiplier = 1.2f);
	void applyEffect(Game& game) override;
	void removeEffect(Game& game) override;
	float getGrowthMultiplier() const override { return growthMultiplier; }
	float getRewardMultiplier() const override { return rewardMultiplier; }
private:
	float growthMultiplier;
	float rewardMultiplier;
};

class EconomicCrisis : public Effect {
public:
	explicit EconomicCrisis(float rewardMultiplier = 1.5f);
	void applyEffect(Game& game) override;
	void removeEffect(Game& game) override;
	float getRewardMultiplier() const override { return rewardMultiplier; }
private:
	float rewardMultiplier;
};

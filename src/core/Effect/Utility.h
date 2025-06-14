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
	float getGrowthMultiplier() const override;
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
	GMO();
	void applyEffect(Game& game) override;
	void removeEffect(Game& game) override;
};

class EconomicCrisis : public Effect {
public:
	EconomicCrisis();
	void applyEffect(Game& game) override;
	void removeEffect(Game& game) override;
};

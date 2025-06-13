#pragma once
class EffectInterface {
public:
	virtual float getGrowthMultiplier() const { return 1.0f; }
	virtual float getRewardMultiplier() const { return 1.0f; }
	virtual ~EffectInterface() = default;
};

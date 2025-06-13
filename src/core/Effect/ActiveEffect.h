#pragma once
#include "Effect.h"
#include <memory>

class ActiveEffect {
private:
	std::unique_ptr<Effect> effect;
	int remainingDuration;

public:
	ActiveEffect(std::unique_ptr<Effect> effect, int duration);
	void tick(Game& game);
	Effect* getEffect() const;
	bool isExpired() const;
};

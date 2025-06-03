#pragma once
#include "Effect.h"

class ActiveEffect {
private:
	Effect* effect;
	int remainingDuration;

public:
	ActiveEffect(Effect* effect, int duration);
	void tick(Game& game);
	Effect* getEffect() const;
	bool isExpired() const;
};

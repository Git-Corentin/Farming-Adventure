#include "ActiveEffect.h"
#include "Game/Game.h"

ActiveEffect::ActiveEffect(Effect* effect, int duration)
	: effect(effect), remainingDuration(duration) {}

void ActiveEffect::tick(Game& game) {
	if (remainingDuration > 0) {
		remainingDuration--;
		if (remainingDuration == 0) {
			effect->removeEffect(game);
		}
	}
}

Effect* ActiveEffect::getEffect() const {
	return effect;
}

bool ActiveEffect::isExpired() const {
	return remainingDuration == 0;
}

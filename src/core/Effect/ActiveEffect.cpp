#include "ActiveEffect.h"
#include "Game/Game.h"

ActiveEffect::ActiveEffect(std::unique_ptr<Effect> effect, int duration)
	: effect(std::move(effect)), remainingDuration(duration) {}

void ActiveEffect::tick(Game& game) {
	if (remainingDuration > 0) {
		remainingDuration--;
		if (remainingDuration == 0) {
			effect->removeEffect(game);
		}
	}
}

Effect* ActiveEffect::getEffect() const {
	return effect.get();
}

bool ActiveEffect::isExpired() const {
	return remainingDuration == 0;
}

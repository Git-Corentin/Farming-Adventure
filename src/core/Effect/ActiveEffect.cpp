#include "ActiveEffect.h"
#include "Game/Game.h"

ActiveEffect::ActiveEffect(std::unique_ptr<Effect> effect, sf::Time duration)
	: effect(std::move(effect)), remainingDuration(duration) {}

void ActiveEffect::tick(Game& game, sf::Time elapsed) {
	if (remainingDuration > sf::Time::Zero) {
		remainingDuration-=elapsed;
		if (remainingDuration <= sf::Time::Zero) {
			effect->removeEffect(game);
		}
	}
}

Effect* ActiveEffect::getEffect() const {
	return effect.get();
}

bool ActiveEffect::isExpired() const {
	return remainingDuration <= sf::Time::Zero;
}

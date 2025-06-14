#pragma once
#include "Effect.h"
#include <memory>
#include <SFML/System/Time.hpp>

class ActiveEffect {
private:
	std::unique_ptr<Effect> effect;
	sf::Time remainingDuration;

public:
	ActiveEffect(std::unique_ptr<Effect> effect, sf::Time duration);
	void tick(Game& game, sf::Time elapsed);
	Effect* getEffect() const;
	bool isExpired() const;

	sf::Time getDuration() const { return remainingDuration; }
};

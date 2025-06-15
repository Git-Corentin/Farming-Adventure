#pragma once
#include <SFML/System/Time.hpp>

class Game;

class AutoClicker {
private:
	sf::Time remainingTime;
	sf::Time timeSinceLastClick;
	const sf::Time clickInterval = sf::seconds(0.1f); // 10 clics par seconde

public:
	AutoClicker() : remainingTime(sf::Time::Zero), timeSinceLastClick(sf::Time::Zero) {}
	void start(int duration);
	void tick(Game& game, sf::Time elapsed);
	bool isActive() const;
};

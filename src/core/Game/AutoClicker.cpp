#include "AutoClicker.h"
#include "Game/Game.h"

void AutoClicker::start(int duration) {
	remainingTime = sf::seconds(duration);
	timeSinceLastClick = sf::Time::Zero;
}

void AutoClicker::tick(Game& game, sf::Time elapsed) {
	if (remainingTime <= sf::Time::Zero)
		return;

	remainingTime -= elapsed;
	timeSinceLastClick += elapsed;

	while (timeSinceLastClick >= clickInterval) {
		timeSinceLastClick -= clickInterval;
		game.autoClickPlot();  // Nouvelle fonction que tu vas créer dans Game
	}

}

bool AutoClicker::isActive() const {
	return remainingTime > sf::Time::Zero;
}

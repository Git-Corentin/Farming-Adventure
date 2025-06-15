#include "ClickablePlot.h"
#include "Game.h"
#include <iostream>

static sf::Font& getSharedFont() {
	static sf::Font font;
	static bool loaded = false;
	if (!loaded && !font.openFromFile("res/Sansation.ttf")) {
		std::cerr << "Erreur chargement police\n";
	} else {
		loaded = true;
	}
	return font;
}

ClickablePlot::ClickablePlot(const sf::Vector2f& size, const sf::Vector2f& position, const std::string& seedName)
	: mShape(size), mText(getSharedFont(), sf::String(seedName), 16)
{
	mShape.setPosition(position);
	mShape.setFillColor(sf::Color::Green);
	mText.setFillColor(sf::Color::Black);
	mText.setPosition({position.x + 10, position.y + 40});
}

void ClickablePlot::draw(sf::RenderWindow& window) const {
	window.draw(mShape);
	window.draw(mText);
}

void ClickablePlot::setGame(Game* game) {
	mGame = game;
}

void ClickablePlot::setSeed(std::shared_ptr<Seed> seed) {
	mCurrentSeed = std::move(seed);
	mText.setString(mCurrentSeed->getName());
	mCurrentSeed->resetClicks();
}

void ClickablePlot::handleClick(sf::Vector2f mousePosition, bool autoClick) {
	if (!mCurrentSeed || !mShape.getGlobalBounds().contains(mousePosition) and autoClick == false) return;

	mCurrentSeed->incrementClicks();

	if (mCurrentSeed->isGrown()) {
		if (mGame) {
			int reward = mCurrentSeed->getMoneyRaised();
			std::string name = mCurrentSeed->getName();

			mGame->onPlotHarvested(reward);
			std::cout << "Récolte de " << name << " réussie, gain: " << reward << "\n";
		}
		mCurrentSeed->resetClicks(); // Visuel si tu veux afficher la progression
	}

	mShape.setFillColor(sf::Color::Yellow); // feedback visuel
}

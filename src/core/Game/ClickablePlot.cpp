#include "ClickablePlot.h"


#include <iostream>

#include "Game.h"

static sf::Font& getSharedFont() {
	static sf::Font font;
	static bool loaded = false;
	if (!loaded) {
		if (!font.openFromFile("res/Sansation.ttf")) {
			std::cerr << "Erreur chargement police\n";
		}
		loaded = true;
	}
	return font;
}

ClickablePlot::ClickablePlot(const sf::Vector2f& size, const sf::Vector2f& position, const std::string& seedName)
	: mShape(size), mText(getSharedFont(),sf::String(seedName), 16)
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
	mText.setString(mCurrentSeed->getName());  // Accès direct si `name` est public ou via getter sinon
	mCurrentSeed->resetClicks();
}

void ClickablePlot::handleClick(sf::Vector2f mousePosition) {
	if (!mCurrentSeed) return;
	if (!mShape.getGlobalBounds().contains(mousePosition)) return;

	mCurrentSeed->applyGrowthModifier(-1);

	if (mCurrentSeed->getClicksToGrow() == 0) {
		if (mGame) {
			mGame->onPlotHarvested(mCurrentSeed->getMoneyRaised());
			std::cout << "Récolte de " << mCurrentSeed->getName() << " réussie, gain: " << mCurrentSeed->getMoneyRaised() << "\n";
		}
		mCurrentSeed->resetClicks();
	}

	mShape.setFillColor(sf::Color::Yellow); // feedback
}

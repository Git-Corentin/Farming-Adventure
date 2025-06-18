#include "ClickablePlot.h"
#include "Game.h"
#include "Texture/TextureManager.h"
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
	: mShape(size), mText(getSharedFont(), sf::String(seedName), 16), mSeedSprite(TextureManager::getInstance().getTexture(seedName))
{
	mShape.setPosition(position);
	mShape.setFillColor(sf::Color::Green);
	mText.setFillColor(sf::Color::Black);
	mText.setPosition({position.x + 10, position.y + 40});
	mSeedSprite.setPosition({position.x + 10, position.y + 40});
	mSeedSprite.setScale({0.6f, 0.6f}); // Ajuste la taille de l'image de la graine
}

void ClickablePlot::draw(sf::RenderWindow& window) const {
	//window.draw(mShape);
	window.draw(mText);
	window.draw(mSeedSprite);
}

void ClickablePlot::setGame(Game* game) {
	mGame = game;
}

void ClickablePlot::setSeed(std::shared_ptr<Seed> seed) {
	mCurrentSeed = std::move(seed);
	mText.setString(mCurrentSeed->getName());
	mCurrentSeed->resetClicks();
	sf::Texture& newTexture = TextureManager::getInstance().getTexture(mCurrentSeed->getName());
	mSeedSprite.setTexture(newTexture, true); // `true` pour réadapter la taille du sprite si besoin
}

void ClickablePlot::handleClick(sf::Vector2f mousePosition, bool autoClick) {
	if (!mCurrentSeed || !mShape.getGlobalBounds().contains(mousePosition) and autoClick == false) return;
	mGame->getSoundManager().playClickSound();

	mCurrentSeed->incrementClicks();

	if (mCurrentSeed->isGrown()) {
		if (mGame) {
			int reward = mCurrentSeed->getMoneyRaised();
			std::string name = mCurrentSeed->getName();

			mGame->onPlotHarvested(reward);
			mGame->getSoundManager().playCoinSound();

			std::cout << "Récolte de " << name << " réussie, gain: " << reward << "\n";
		}
		mCurrentSeed->resetClicks(); // Visuel si tu veux afficher la progression
	}

	mShape.setFillColor(sf::Color::Yellow); // feedback visuel
}

void ClickablePlot::SetPosition(const sf::Vector2f& position) {
	mShape.setPosition(position);
	mSeedSprite.setPosition(position);
	mText.setPosition({ position.x + 10, position.y - 50});
}
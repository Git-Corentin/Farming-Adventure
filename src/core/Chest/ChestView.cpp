// ChestView.cpp
#include "ChestView.h"
#include "Game/Game.h"
#include "Chest.h"
#include "Texture/TextureManager.h"
#include <iostream>

ChestView::ChestView(const std::string& closedTexturePath, const std::string& openedTexturePath, std::unique_ptr<Chest> chest, sf::Vector2f position)
	: mChest(std::move(chest)),
	  mPosition(position)
{
	loadTextures(closedTexturePath, openedTexturePath);
	mSprite = std::make_unique<sf::Sprite>(mClosedTexture);  // Ici on passe la texture, constructeur ok
	mSprite->setPosition(mPosition);
	mSprite->setScale({0.6f, 0.6f});
}


void ChestView::loadTextures(const std::string& closedPath, const std::string& openedPath) {
	if (!mClosedTexture.loadFromFile(closedPath)) {
		std::cerr << "Erreur : impossible de charger la texture fermée depuis " << closedPath << "\n";
	}

	if (!mOpenedTexture.loadFromFile(openedPath)) {
		std::cerr << "Erreur : impossible de charger la texture ouverte depuis " << openedPath << "\n";
	}
}

void ChestView::handleClick(sf::Vector2f mousePos, Game& game) {
	if (mSprite->getGlobalBounds().contains(mousePos)) {
		bool opened = mChest->open(game);  // Tente d'ouvrir le coffre
		if (opened) {
			game.prepareRewardDisplay(mRewardsToShow);  // Copier les récompenses générées

			mIsOpened = true;  // Passe en état ouvert **seulement si ça a marché**
			mOpenClock.restart();
			mRewardClock.restart();
			mCurrentRewardIndex = 0;
		}
	}
}

void ChestView::update() {
	if (mIsOpened && mOpenClock.getElapsedTime().asSeconds() > 1.0f) {
		mIsOpened = false;
	}
	if (mCurrentRewardIndex < mRewardsToShow.size() &&
		mRewardClock.getElapsedTime().asSeconds() > mRewardDisplayDuration) {
		mRewardClock.restart();
		++mCurrentRewardIndex;
		}
}

void ChestView::draw(sf::RenderWindow& window) {
	mSprite->setTexture(mIsOpened ? mOpenedTexture : mClosedTexture);
	window.draw(*mSprite);

	if (mCurrentRewardIndex < mRewardsToShow.size()) {
		std::string reward = mRewardsToShow[mCurrentRewardIndex];
		sf::Texture& tex = TextureManager::getInstance().getTexture(reward);
		sf::Sprite rewardSprite(tex);
		rewardSprite.setPosition({mPosition.x, mPosition.y - 100});  // au-dessus du coffre
		rewardSprite.setScale({0.4f, 0.4f});
		window.draw(rewardSprite);
	}
}

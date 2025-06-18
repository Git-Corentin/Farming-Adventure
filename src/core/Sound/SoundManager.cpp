#include "SoundManager.h"
#include <iostream>

SoundManager::SoundManager() {
	loadSounds();
}

void SoundManager::loadSounds() {

	if (!mBackgroundMusic.openFromFile("res/music/background.mp3")) {
		std::cerr << "Erreur: Impossible de charger la musique de fond." << std::endl;
	} else {
		mBackgroundMusic.setLooping(true);
		mBackgroundMusic.setVolume(50);
	}

	if (!mChestBuffer.loadFromFile("res/music/chest_opening.mp3")) {
		std::cerr << "Erreur: Impossible de charger le son de coffre." << std::endl;
	} else {
		mChestSound = std::make_unique<sf::Sound>(mChestBuffer);
		mChestSound->setVolume(75);
	}

	if (!mChestLockedBuffer.loadFromFile("res/music/chest_lock.mp3")) {
		std::cerr << "Erreur: Impossible de charger le son de coffre." << std::endl;
	} else {
		mChestLockedSound = std::make_unique<sf::Sound>(mChestLockedBuffer);
		mChestLockedSound->setVolume(75);
	}

	if (!mClickBuffer.loadFromFile("res/music/click.mp3")) {
		std::cerr << "Erreur: Impossible de charger le son de clic." << std::endl;
	} else {
		mClickSound = std::make_unique<sf::Sound>(mClickBuffer);
		mClickSound->setVolume(25);
	}

	if (!mCoinBuffer.loadFromFile("res/music/coin.mp3")) {
		std::cerr << "Erreur: Impossible de charger le son de pièce." << std::endl;
	} else {
		mCoinSound = std::make_unique<sf::Sound>(mCoinBuffer);
		mCoinSound->setVolume(50);
	}

	if (!mFailureBuffer.loadFromFile("res/music/failure.mp3")) {
		std::cerr << "Erreur: Impossible de charger le son d'échec." << std::endl;
	} else {
		mFailureSound = std::make_unique<sf::Sound>(mFailureBuffer);
		mFailureSound->setVolume(50);
	}

}

void SoundManager::playBackgroundMusic() {
	mBackgroundMusic.play();
}

void SoundManager::playChestSound() const {
	if (mChestSound) {
		mChestSound->play();
	}
}

void SoundManager::playChestLockedSound() const {
	if (mChestLockedSound) {
		mChestLockedSound->play();
	}
}

void SoundManager::playClickSound() const {
	if (mClickSound) {
		mClickSound->play();
	}
}

void SoundManager::playCoinSound() const {
	if (mCoinSound) {
		mCoinSound->play();
	}
}

void SoundManager::playFailureSound() const {
	if (mFailureSound) {
		mFailureSound->play();
	}
}



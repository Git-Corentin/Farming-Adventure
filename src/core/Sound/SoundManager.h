#pragma once
#include <SFML/Audio.hpp>

class SoundManager {
public:

	SoundManager();
	void loadSounds();
	void playBackgroundMusic();
	void playChestSound() const;
	void playChestLockedSound() const;
	void playClickSound() const;
	void playCoinSound() const;
	void playFailureSound() const;


private:
	sf::Music mBackgroundMusic;

	sf::SoundBuffer mChestBuffer;
	std::unique_ptr<sf::Sound> mChestSound;

	sf::SoundBuffer mChestLockedBuffer;
	std::unique_ptr<sf::Sound> mChestLockedSound;

	sf::SoundBuffer mClickBuffer;
	std::unique_ptr<sf::Sound> mClickSound;

	sf::SoundBuffer mCoinBuffer;
	std::unique_ptr<sf::Sound> mCoinSound;

	sf::SoundBuffer mFailureBuffer;
	std::unique_ptr<sf::Sound> mFailureSound;


};
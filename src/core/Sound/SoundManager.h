#pragma once
#include <SFML/Audio.hpp>
#include <SFML/Audio/SoundSource.hpp>

class SoundManager {
public:

	SoundManager();
	void loadSounds();
	void playBackgroundMusic();
	void playHempMusic();
	void playChestSound() const;
	void playChestLockedSound() const;
	void playClickSound() const;
	void playCoinSound() const;
	void playFailureSound() const;

	sf::Music& getHempMusic() { return mHempMusic; }

private:
	sf::Music mBackgroundMusic;
	sf::Music mHempMusic;

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
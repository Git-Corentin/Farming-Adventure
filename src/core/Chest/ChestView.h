// ChestView.h
#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include <string>
#include "Chest.h"
#include <chrono>

class Game;
class Chest;

class ChestView {
public:
	ChestView(const std::string& closedTexturePath, const std::string& openedTexturePath, std::unique_ptr<Chest> chest, sf::Vector2f position);

	void draw(sf::RenderWindow& window);
	void update();
	void handleClick(sf::Vector2f mousePos, Game& game);

private:
	std::unique_ptr<sf::Sprite> mSprite;
	sf::Texture mClosedTexture, mOpenedTexture;
	bool mIsOpened = false;
	sf::Clock mOpenClock;

	std::vector<std::string> mRewardsToShow;
	sf::Clock mRewardClock;
	size_t mCurrentRewardIndex = 0;
	float mRewardDisplayDuration = 1.0f;

	std::unique_ptr<Chest> mChest;
	sf::Vector2f mPosition;

	void loadTextures(const std::string& closedPath, const std::string& openedPath);
};

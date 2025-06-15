#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>
#include "SeedReservoir.h"
#include "AutoClicker.h"
#include "Effect/ActiveEffect.h"
#include "Soil.h"
#include <list>
#include "Enum/ChestType.h"
#include "AutoClicker.h"

class Seed; // Fwd declarations de tes entités internes
#include "ClickablePlot.h"

class Game {
public:
	Game();
	void run();

	void startGame();
	void handleClickOnPlot();
	void buyChest(ChestType type);
	void applyEffect(Effect* effect);
	void plantNextSeed();
	void onPlotHarvested(int reward);
	void removeMoney(int amount);
	void addMoney(int amount);

	SeedReservoir& getSeedReservoir() { return seedReservoir; }
	int getMoney() const { return mMoney; }

	float computeTotalGrowthMultiplier() const;
	float computeTotalRewardMultiplier() const;

	void autoClickPlot() const;
	AutoClicker& getAutoClicker() {return autoClicker;}





private:
	void processEvents();
	void update(sf::Time elapsedTime);
	void render();
	void updateStatistics(sf::Time elapsedTime);

	static const sf::Time TimePerFrame;

	sf::RenderWindow mWindow{sf::VideoMode({800, 600}), "Farming Adventure"};
	sf::Font mFont;
	sf::Text mStatisticsText{mFont};
	sf::Time mStatisticsUpdateTime;
	std::size_t mStatisticsNumFrames{0};


	std::unique_ptr<ClickablePlot> mClickablePlot;

	int mMoney = 0;
	sf::Text mMoneyText;

	Seed* currentPlantOnPlot;
	SeedReservoir seedReservoir;
	std::list<ActiveEffect> activeEffects;
	Soil soil;
	AutoClicker autoClicker;

	float growthBonus = 1.0f;  // 1.0f = normal, <1 = plus rapide
	float rewardBonus = 1.0f;  // 1.0f = normal, >1 = plus d'argent


};

#endif // GAME_HPP

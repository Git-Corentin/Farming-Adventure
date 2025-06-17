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
#include "Chest/ChestView.h"

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
	void addMoney(uint64_t amount);

	SeedReservoir& getSeedReservoir() { return seedReservoir; }
	uint64_t getMoney() const { return mMoney; }

	float computeTotalGrowthMultiplier() const;
	float computeTotalRewardMultiplier() const;

	void autoClickPlot() const;
	AutoClicker& getAutoClicker() {return autoClicker;}

	Soil getSoil() const { return soil; }
	void resetSoil() { soil.reset(); }
	void degradeSoil(int value) { soil.degrade(value); }

	bool isPesticideActive() const;

	void addActiveEffect(std::unique_ptr<Effect> effect, sf::Time duration);
    bool isEffectActive(const std::string& effectName) const;

	std::vector<std::unique_ptr<ChestView>> mChestViews;
	void prepareRewardDisplay(std::vector<std::string>& rewards);

	void addRewardToDisplay(const std::string& reward);


private:
	void processEvents();
	void update(sf::Time elapsedTime);
	void render();
	void updateStatistics(sf::Time elapsedTime);


	static const sf::Time TimePerFrame;

	sf::RenderWindow mWindow{sf::VideoMode({1000, 600}), "Farming Adventure"};
	sf::Font mFont;
	sf::Text mStatisticsText{mFont};
	sf::Time mStatisticsUpdateTime;
	std::size_t mStatisticsNumFrames{0};


	std::unique_ptr<ClickablePlot> mClickablePlot;

	uint64_t mMoney = 0;
	uint64_t maxMoney = 9223372036854775807; //uint64_t max value
	sf::Text mMoneyText;

	Seed* currentPlantOnPlot;
	SeedReservoir seedReservoir;
	std::list<ActiveEffect> activeEffects;
	Soil soil;
	AutoClicker autoClicker;

	float growthBonus = 1.0f;  // 1.0f = normal, <1 = plus rapide
	float rewardBonus = 1.0f;  // 1.0f = normal, >1 = plus d'argent

	std::vector<std::string> mPendingRewards;


};

#endif // GAME_HPP

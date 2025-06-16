#include <gtest/gtest.h>
#include "Game/Game.h"
#include "Game/SeedReservoir.h"

TEST(Initialization, GameStartsWithDefaultValues) {
	Game game;
	EXPECT_EQ(game.getMoney(), 0);
	EXPECT_EQ(game.getSeedReservoir().getSelectedSeed(), SeedType::WHEAT);
	EXPECT_EQ(game.getSoil().getDegradationRatio(), 0.0f);
}


TEST(SeedLogic, BacksToWheatWhenNoSeeds) {
    Game game;
    game.getSeedReservoir().setSelectedSeed(SeedType::TREE);  // Trying to plant a World Tree seed but inventory is 0

    game.plantNextSeed();

    EXPECT_EQ(game.getSeedReservoir().getSelectedSeed(), SeedType::WHEAT);
}

TEST(MoneyLogic, NoNegativeMoneyAmount) {
	Game game;
	game.addMoney(2147483648); // Maximum positive value for int +1
	ASSERT_GT(game.getMoney(), 0); // Should not allow money to exceed int limits
}
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

TEST(SeedLogic, PlantingUsesCorrectSeed) {
    Game game;
    game.getSeedReservoir().addSeed(SeedType::TREE, 1);
    game.getSeedReservoir().setSelectedSeed(SeedType::TREE);

    game.plantNextSeed();

    EXPECT_EQ(game.getSeedReservoir().getSeedQuantity(SeedType::TREE), 0);
}

TEST(MoneyLogic, NoOverflowMoneyAmount) {
	Game game;
	game.addMoney(9223372036854775807); // Maximum positive value for uint64_t
	game.addMoney(1); // Attempt to exceed the limit
	ASSERT_EQ(game.getMoney(), 0); // Should not allow money to exceed uint64_t limits and sends the player back to 0$
}

/*TEST(EffectLogic, CleaningRobotResetsSoilProperly) {
    Game game;
	game.getSoil().degrade(500); // 50% degradation

    auto effect = std::make_unique<CleaningRobot>(); // suppose it increases reward
	game.applyEffect(effect.get());

    float after = game.getSoil().getDegradationRatio;
    EXPECT_EQ(after, 0);
}*/
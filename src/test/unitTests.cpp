#include <gtest/gtest.h>
#include "Game/Game.h"
#include "Game/SeedReservoir.h"
#include "Effect/Utility.h"
#include "Effect/Malus.h"

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

TEST(EffectLogic, CleaningRobotResetsSoilProperly) {
    Game game;
	game.getSoil().degrade(500); // 50% degradation

	std::cout << "Soil degradation ratio before applying robot:" << game.getSoil().getDegradationRatio() << std::endl;

    auto effect = std::make_unique<CleaningRobot>();
	effect->applyEffect(game);

    float after = game.getSoil().getDegradationRatio();

    EXPECT_EQ(after, 0);
}

TEST(EffectLogic, ExpirationDoesntMakeSeedQuantityNegative) {
	Game game;
	
	game.getSeedReservoir().addSeed(SeedType::ORCHID, 1);
	game.getSeedReservoir().addSeed(SeedType::BAMBOO, 1);

	auto effect = std::make_unique<Expiration>();
	effect->applyEffect(game);

	bool noNegativeSeeds = true;
	for (int i = 0; i <= static_cast<int>(SeedType::TREE); ++i) {
		SeedType type = static_cast<SeedType>(i);
		if (game.getSeedReservoir().getSeedQuantity(type) < 0) {
			noNegativeSeeds = false;
			break;
		}
	}
	EXPECT_TRUE(noNegativeSeeds);
} //Making sure that removing 3 random seeds doen't make the quantity negative
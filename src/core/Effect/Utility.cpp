
#include "Utility.h"

#include "Game/Game.h"
#include "Effect/Effect.h"
#include <iostream>

// ______FERTILIZER______
Fertilizer::Fertilizer(float multiplier)
    : growthMultiplier(multiplier) {
    name = "Fertilizer";
    duration = 20;
}

void Fertilizer::applyEffect(Game& game) {
    // Aucun état direct à modifier ici puisque le Game::computeTotalGrowthMultiplier les applique dynamiquement
    std::cout << "Fertilizer applied: growth multiplier = " << growthMultiplier << "\n";
}

void Fertilizer::removeEffect(Game& game) {
    std::cout << "Fertilizer expired\n";
}

// ______HARVESTER______

Harvester::Harvester() {
    name = "Harvester";
    duration = 20;
}

void Harvester::applyEffect(Game& game) {
    std::cout << "Harvester launched: auto-clicking\n";
    game.getAutoClicker().start(duration);
}

void Harvester::removeEffect(Game& game) {
    std::cout << "Harvester expired\n";
}

// ______PESTICIDE______

Pesticide::Pesticide() {
    name = "Pesticide";
    duration = 20;
}

void Pesticide::applyEffect(Game& game) {
    std::cout << "Pesticide applied\n";
}

void Pesticide::removeEffect(Game& game) {
    std::cout << "Pesticide expired\n";
}

// ______CLEANING ROBOT______

CleaningRobot::CleaningRobot() {
    name = "Cleaning Robot";
    duration = 0;
}

void CleaningRobot::applyEffect(Game& game) {
    std::cout << "Cleaning Robot applied: soil degradation reset\n";
    game.resetSoil();
}


// ______Economic Crisis______

EconomicCrisis::EconomicCrisis(float rewardMultiplier)
    : rewardMultiplier(rewardMultiplier) {
    name = "Economic Crisis";
    duration = 20;
}

void EconomicCrisis::applyEffect(Game& game) {
    std::cout << "reward multiplier = " << rewardMultiplier << "\n";
}

void EconomicCrisis::removeEffect(Game& game) {
    std::cout << "Economic Crisis expired\n";
}

// ______GMO______

GMO::GMO(float growthMultiplier, float rewardMultiplier)
    : growthMultiplier(growthMultiplier), rewardMultiplier(rewardMultiplier) {
    name = "GMO";
    duration = 20;
}

void GMO::applyEffect(Game& game) {
    std::cout << "GMO applied: growth multiplier = " << growthMultiplier
              << ", reward multiplier = " << rewardMultiplier << "\n";
}

void GMO::removeEffect(Game& game) {
    std::cout << "GMO expired\n";
}


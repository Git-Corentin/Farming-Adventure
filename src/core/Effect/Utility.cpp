
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

float Fertilizer::getGrowthMultiplier() const {
    return growthMultiplier;
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
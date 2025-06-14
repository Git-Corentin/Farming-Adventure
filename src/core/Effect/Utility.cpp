
#include "Utility.h"

#include "Game/Game.h"
#include "Effect/Effect.h"
#include <iostream>

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
#include "Malus.h"
#include "Game/Game.h"
#include <iostream>

// ______STORM______
Storm::Storm() {
	name = "Storm";
	duration = 0;
}

void Storm::applyEffect(Game& game) {
	std::cout << "Storm applied: the soil is degraded\n";
	game.degradeSoil(400); // Dégradation du sol
}

// ______FROST______
Frost::Frost(float gmultiplier, float rmultiplier) 
	: growthMultiplier(gmultiplier), rewardMultiplier(rmultiplier) {
	name = "Frost";
	duration = 15;
}

void Frost::applyEffect(Game& game) {
	std::cout << "Frost applied: soil became frozen\n";
}

void Frost::removeEffect(Game& game) {
	std::cout << "Frost effect removed\n";
}


// ______THIEF______
Thief::Thief() {
	name = "Thief";
	duration = 0;
}

void Thief::applyEffect(Game& game) {
	int stolenAmount = game.getMoney() / 3;
	game.removeMoney(stolenAmount);
	std::cout << "Thief applied: " << stolenAmount << " coins stolen\n";
}

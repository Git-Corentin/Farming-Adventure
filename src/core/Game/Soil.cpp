#include "Soil.h"
#include <algorithm>

void Soil::worsen() {
	degradationLevel = std::min(degradationLevel + 4, maxDegradationLevel);  // +4 par récolte
}

int Soil::getDegradationPenalty() const {
	return degradationLevel / 40;  // +1 clic tous les 40 points
}

float Soil::getRewardMultiplier() const {
	float factor = 1.0f - (static_cast<float>(degradationLevel) / maxDegradationLevel) * 0.5f;
	if (factor > 0.95f) return 1.0f;  // pas de pénalité avant 10 de dégradation
	return std::max(factor, 0.5f);    // entre 1.0 et 0.5
}

float Soil::getDegradationRatio() const {
	return static_cast<float>(degradationLevel) / maxDegradationLevel;
}

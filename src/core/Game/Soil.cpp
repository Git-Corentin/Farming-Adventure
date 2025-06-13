#include "Soil.h"
#include <algorithm>

void Soil::worsen() {
	degradationLevel = std::min(degradationLevel + 4, maxDegradationLevel);  // +4 par récolte
}

float Soil::getGrowthMultiplier() const {
	return 1.0f + (static_cast<float>(degradationLevel) / maxDegradationLevel) * 0.5f; // jusqu’à *1.5
}

float Soil::getRewardMultiplier() const {
	float factor = 1.0f - (static_cast<float>(degradationLevel) / maxDegradationLevel) * 0.5f;
	return std::max(factor, 0.5f);    // entre 1.0 et 0.5
}

float Soil::getDegradationRatio() const {
	return static_cast<float>(degradationLevel) / maxDegradationLevel;
}

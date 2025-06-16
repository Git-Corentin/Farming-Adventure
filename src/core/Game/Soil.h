#pragma once

#include "Effect/EffectInterface.h"

class Soil : public EffectInterface{
private:
	int degradationLevel = 0;           // Progression lente sur plusieurs récoltes
	const int maxDegradationLevel = 1000;

public:
	void worsen();                      // À appeler à chaque récolte
	float getDegradationRatio() const;  // Pour affichage

	float getGrowthMultiplier() const override;
	float getRewardMultiplier() const override;

	void degrade(int percentage);

	void reset() {
        degradationLevel = 0;  // Réinitialise le sol
    }
};

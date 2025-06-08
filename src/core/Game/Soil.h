#pragma once

class Soil {
private:
	int degradationLevel = 0;           // Progression lente sur plusieurs récoltes
	const int maxDegradationLevel = 1000;

public:
	void worsen();                      // À appeler à chaque récolte
	int getDegradationPenalty() const;  // Pour ajuster les clics nécessaires
	float getRewardMultiplier() const;  // Pour ajuster l'argent
	float getDegradationRatio() const;  // Pour affichage
};

#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class Seed; // Fwd declarations de tes entités internes
#include "ClickablePlot.h"

class Game {
public:
	Game();
	void run();

private:
	void processEvents();
	void update(sf::Time elapsedTime);
	void render();
	void updateStatistics(sf::Time elapsedTime);

	static const sf::Time TimePerFrame;

	sf::RenderWindow mWindow{sf::VideoMode({800, 600}), "Farming Adventure"};
	sf::Font mFont;
	sf::Text mStatisticsText{mFont};
	sf::Time mStatisticsUpdateTime;
	std::size_t mStatisticsNumFrames{0};

	// Exemple de visuel pour la plante en cours
	std::unique_ptr<ClickablePlot> mClickablePlot;
};

#endif // GAME_HPP

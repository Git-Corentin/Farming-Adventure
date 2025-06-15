#ifndef CLICKABLE_PLOT_H
#define CLICKABLE_PLOT_H

#include <SFML/Graphics.hpp>
#include "Seed.h"
class Game;
#include <functional>

class ClickablePlot {
public:
	ClickablePlot(const sf::Vector2f& size, const sf::Vector2f& position, const std::string& seedName);

	void draw(sf::RenderWindow& window) const;
	void handleClick(sf::Vector2f mousePosition, bool autoClick = false);

	void setSeed(std::shared_ptr<Seed> seed);
	void setGame(Game* game);

private:
	sf::RectangleShape mShape;
	sf::Text mText;

	std::shared_ptr<Seed> mCurrentSeed;

	Game* mGame = nullptr;
};

#endif // CLICKABLE_PLOT_H

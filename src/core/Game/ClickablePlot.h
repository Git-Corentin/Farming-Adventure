#ifndef CLICKABLE_PLOT_H
#define CLICKABLE_PLOT_H
#include <SFML/Graphics.hpp>
#include "Seed.h"
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
class Game;



class ClickablePlot {
public:
	ClickablePlot(const sf::Vector2f& size, const sf::Vector2f& position, const std::string& seedName);

	void draw(sf::RenderWindow& window) const;
	void handleClick(sf::Vector2f mousePosition, bool autoClick = false);

	void setSeed(std::shared_ptr<Seed> seed);
	void setGame(Game* game);

	void SetPosition(const sf::Vector2f& position);

private:
	sf::RectangleShape mShape;
	sf::Text mText;

	std::shared_ptr<Seed> mCurrentSeed;
	sf::Sprite mSeedSprite;
	Game* mGame = nullptr;
};

#endif // CLICKABLE_PLOT_H

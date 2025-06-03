#ifndef CLICKABLE_PLOT_H
#define CLICKABLE_PLOT_H

#include <SFML/Graphics.hpp>
#include <functional>

class ClickablePlot {
public:
	ClickablePlot(const sf::Vector2f& size, const sf::Vector2f& position);

	void draw(sf::RenderWindow& window) const;
	bool contains(sf::Vector2f point) const;
	void setOnClick(std::function<void()> callback);
	void handleClick(sf::Vector2f mousePosition);

private:
	sf::RectangleShape mShape;
	std::function<void()> mOnClick;
};

#endif // CLICKABLE_PLOT_H

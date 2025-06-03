#include "ClickablePlot.h"

ClickablePlot::ClickablePlot(const sf::Vector2f& size, const sf::Vector2f& position)
	: mOnClick(nullptr) {
	mShape.setSize(size);
	mShape.setPosition(position);
	mShape.setFillColor(sf::Color::Green);
}

void ClickablePlot::draw(sf::RenderWindow& window) const {
	window.draw(mShape);
}

bool ClickablePlot::contains(sf::Vector2f point) const {
	return mShape.getGlobalBounds().contains(point);
}

void ClickablePlot::setOnClick(std::function<void()> callback) {
	mOnClick = std::move(callback);
}

void ClickablePlot::handleClick(sf::Vector2f mousePosition) {
	if (contains(mousePosition) && mOnClick) {
		mOnClick();  // Appelle le callback défini dans Game
		mShape.setFillColor(sf::Color::Yellow);  // Feedback visuel
	}
}

#include "Clicker.h"

Clicker::Clicker(float radius, sf::Color color, float x, float y,
                         float speedX, float speedY) {
  mShape.setRadius(radius);
  mShape.setFillColor(color);
  mShape.setPosition({x, y});
  mSpeed.x = speedX;
  mSpeed.y = speedY;
}

void Clicker::drawCurrent(sf::RenderWindow &window) const {
  window.draw(mShape);
}

void Clicker::update(const sf::Time &elapsedTime) {
  mShape.move(mSpeed * elapsedTime.asSeconds());
}

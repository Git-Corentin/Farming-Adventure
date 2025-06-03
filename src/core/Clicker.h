#ifndef SIMPLE_GAME_ROUND_TARGET_H
#define SIMPLE_GAME_ROUND_TARGET_H

#include <SFML/Graphics.hpp>

class Clicker {
 public:
  Clicker(float radius, sf::Color color, float x, float y, float speedX,
              float speedY);
  void drawCurrent(sf::RenderWindow &window) const;
  void update(const sf::Time &elapsedTime);

 private:
  sf::CircleShape mShape;
  sf::Vector2f mSpeed;
};

#endif  // SIMPLE_GAME_ROUND_TARGET_H

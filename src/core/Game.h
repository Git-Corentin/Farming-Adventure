#ifndef BOOK_GAME_HPP
#define BOOK_GAME_HPP

#include <SFML/Graphics.hpp>

#include "Clicker.h"

class Game {
 public:
  Game();
  Game(const Game &) = delete;
  Game &operator=(const Game &) = delete;
  void run();

 private:
  void processEvents();
  void update(sf::Time elapsedTime);
  void render();

  void updateStatistics(sf::Time elapsedTime);

  static const sf::Time TimePerFrame;

  sf::RenderWindow mWindow{sf::VideoMode({640, 480}), "SFML Application"};
  sf::Texture mTexture;
  Clicker mTarget{50.f, sf::Color::Cyan, 100.f, 100.f, 100.f, 100.f};
  sf::Font mFont;
  sf::Text mStatisticsText{mFont};
  sf::Time mStatisticsUpdateTime;

  std::size_t mStatisticsNumFrames{0};
};

#endif  // BOOK_GAME_HPP

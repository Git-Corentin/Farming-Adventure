#include "Game.h"
#include "ClickablePlot.h"  // À créer : représente la parcelle cliquable

#include <cassert>
#include <format>
#include <optional>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>


const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game(): mMoneyText(mFont) {
  assert(mFont.openFromFile("res/Sansation.ttf"));

  mStatisticsText.setFont(mFont);
  mStatisticsText.setPosition({5.f, 5.f});
  mStatisticsText.setCharacterSize(14);

  mMoneyText.setPosition({5.f, 25.f});
  mMoneyText.setCharacterSize(16);
  mMoneyText.setFillColor(sf::Color::White);
  mMoneyText.setString("Argent: 0");

  auto wheat = std::make_shared<WheatSeed>();
  mClickablePlot = std::make_unique<ClickablePlot>(
    sf::Vector2f(100.f, 100.f), sf::Vector2f(300.f, 300.f), "Tomate");
  mClickablePlot->setGame(this);
  mClickablePlot->setSeed(wheat);
}

void Game::onPlotHarvested(int reward) {
  mMoney += reward;
  mMoneyText.setString("Argent: " + std::to_string(mMoney));
}

void Game::run() {
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  mWindow.setFramerateLimit(60);

  while (mWindow.isOpen()) {
    sf::Time elapsedTime = clock.restart();
    timeSinceLastUpdate += elapsedTime;

    while (timeSinceLastUpdate > TimePerFrame) {
      timeSinceLastUpdate -= TimePerFrame;

      processEvents();
      update(TimePerFrame);
    }

    updateStatistics(elapsedTime);
    render();
  }
}

void Game::processEvents() {
  while (const std::optional<sf::Event> event = mWindow.pollEvent()) {
    // Check if the optional contains an event
    if (!event) {
      continue;
    }

    if (event->is<sf::Event::Closed>()) {
      mWindow.close();
    } else if (const auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>()) {

      if (mouseEvent->button == sf::Mouse::Button::Left) {

        sf::Vector2f mousePos = {(float)mouseEvent->position.x, (float)mouseEvent->position.y};
        mClickablePlot->handleClick(mousePos);

      }
    }
    // You can add more else if (const auto* ... = event->getIf<sf::Event::SomeOtherEvent>()) { ... }
    // for other event types.
  }
}

void Game::update(sf::Time elapsedTime) {
  // Gestion du temps, effets temporaires, auto-click, etc.
}

void Game::render() {
  mWindow.clear();
  mClickablePlot->draw(mWindow);
  mWindow.draw(mStatisticsText);
  mWindow.draw(mMoneyText);
  mWindow.display();
}

void Game::updateStatistics(sf::Time elapsedTime) {
  mStatisticsUpdateTime += elapsedTime;
  mStatisticsNumFrames += 1;

  if (mStatisticsUpdateTime >= sf::seconds(1.0f)) {
    mStatisticsText.setString(std::format(
      "FPS: {}\nUpdate time: {}us",
      mStatisticsNumFrames,
      mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames
    ));

    mStatisticsUpdateTime -= sf::seconds(1.0f);
    mStatisticsNumFrames = 0;
  }
}

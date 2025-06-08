#include "Game.h"
#include "ClickablePlot.h"  // À créer : représente la parcelle cliquable
#include <imgui.h>
#include <imgui-SFML.h>

#include <cassert>
#include <format>
#include <iostream>
#include <optional>
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include "SeedFactory.h"  // Pour créer des graines
#include "SeedReservoir.h"  // Pour la gestion des graines
#include "Chest/Chest.h"  // Pour ouvrir le coffre à graines


const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);

Game::Game(): mMoneyText(mFont) {
  assert(mFont.openFromFile("res/Sansation.ttf"));

  mStatisticsText.setFont(mFont);
  mStatisticsText.setPosition({5.f, 5.f});
  mStatisticsText.setCharacterSize(14);

  mMoneyText.setPosition({5.f, 35.f});
  mMoneyText.setCharacterSize(16);
  mMoneyText.setFillColor(sf::Color::White);
  mMoneyText.setString("Argent: " + std::to_string(mMoney));

  mClickablePlot = std::make_unique<ClickablePlot>(
    sf::Vector2f(100.f, 100.f), sf::Vector2f(300.f, 300.f), ""); // Nom mis à jour dans setSeed
  mClickablePlot->setGame(this);
  seedReservoir.setSelectedSeed(SeedType::WHEAT); // Blé par défaut
  plantNextSeed();
}

void Game::onPlotHarvested(int baseReward) {
  float multiplier = soil.getRewardMultiplier();
  int adjustedReward = static_cast<int>(baseReward * multiplier);

  addMoney(std::max(0, adjustedReward)); // Ne jamais descendre en dessous de 0

  soil.worsen(); // Le sol se dégrade à chaque récolte

  plantNextSeed(); // Une nouvelle graine est plantée automatiquement
}

void Game::run() {
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  mWindow.setFramerateLimit(60);
  ImGui::SFML::Init(mWindow);

  while (mWindow.isOpen()) {
    sf::Time elapsedTime = clock.restart();
    timeSinceLastUpdate += elapsedTime;

    ImGui::SFML::Update(mWindow, elapsedTime);


    ImGui::Begin("Seed Reservoir");
    for (int i = 0; i <= static_cast<int>(SeedType::TREE); ++i) {
      SeedType type = static_cast<SeedType>(i);
      int qty = seedReservoir.getSeedQuantity(type);

      std::string label = SeedFactory::SeedTypeToString(type) + " (" + std::to_string(qty) + ")";

      if (ImGui::Selectable(label.c_str(), seedReservoir.getSelectedSeed() == type, 0,
          ImVec2(200, 0))) {
        if (qty > 0 || SeedReservoir::isWheat(type)) {
          seedReservoir.setSelectedSeed(type);
        }
          }
    }
    if (ImGui::Button("Recevoir une graine aléatoire !")) {
      int maxType = static_cast<int>(SeedType::TREE);
      SeedType randomType;

      do {
        randomType = static_cast<SeedType>(rand() % (maxType + 1));
      } while (SeedReservoir::isWheat(randomType)); // évite de donner du blé

      seedReservoir.addSeed(randomType, 1);
    }
    if (ImGui::Button("Ouvrir coffre à graines")) {
      SeedChest chest;
      chest.open(*this);
    }
    ImGui::End();

    ImGui::Begin("Sol");

    ImGui::Text("Degradation du sol :");
    float degradationRatio = soil.getDegradationRatio();
    std::string progressLabel = std::format("{:.0f} %%", degradationRatio * 100);
    ImGui::ProgressBar(degradationRatio, ImVec2(200, 20), progressLabel.c_str());

    ImGui::Text("Pénalité de clics : +%d", soil.getDegradationPenalty());
    ImGui::Text("Multiplicateur de récompense : %.2fx", soil.getRewardMultiplier());

    ImGui::End();

    while (timeSinceLastUpdate > TimePerFrame) {
      timeSinceLastUpdate -= TimePerFrame;

      processEvents();
      update(TimePerFrame);
    }

    updateStatistics(elapsedTime);
    render();
  }
  ImGui::SFML::Shutdown();
}

void Game::processEvents() {
  while (const std::optional<sf::Event> event = mWindow.pollEvent()) {
    // Check if the optional contains an event

    if (!event) {
      continue;
    }
    ImGui::SFML::ProcessEvent(mWindow, *event);

    if (event->is<sf::Event::Closed>()) {
      mWindow.close();
    } else if (const auto* mouseEvent = event->getIf<sf::Event::MouseButtonPressed>()) {

      if (mouseEvent->button == sf::Mouse::Button::Left) {

        sf::Vector2f mousePos = {(float)mouseEvent->position.x, (float)mouseEvent->position.y};
        mClickablePlot->handleClick(mousePos);

      }
    }

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
  ImGui::SFML::Render(mWindow);
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

void Game::plantNextSeed() {
  SeedType typeToPlant = seedReservoir.getSelectedSeed();

  if (!SeedReservoir::isWheat(typeToPlant) && seedReservoir.getSeedQuantity(typeToPlant) <= 0) {
    typeToPlant = SeedType::WHEAT;
    seedReservoir.setSelectedSeed(typeToPlant);
  }

  if (!SeedReservoir::isWheat(typeToPlant)) {
    seedReservoir.removeSeed(typeToPlant, 1);
  }

  auto newSeed = SeedFactory::createSeed(typeToPlant);

  int growthPenalty = soil.getDegradationPenalty();
  float rewardMultiplier = soil.getRewardMultiplier();

  newSeed->applyPenaltiesAndBoosts(growthPenalty, rewardMultiplier);

  std::cout << "Nouvelle graine : " << SeedFactory::SeedTypeToString(typeToPlant)
            << ", clics nécessaires : " << newSeed->getClicksToGrow() << "\n";

  mClickablePlot->setSeed(newSeed);
}

void Game::addMoney(int amount) {
  mMoney += amount;
  mMoneyText.setString("Argent: " + std::to_string(mMoney));
}

void Game::removeMoney(int amount) {
  mMoney -= amount;
  mMoneyText.setString("Argent: " + std::to_string(mMoney));
}
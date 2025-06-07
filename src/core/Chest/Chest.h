#pragma once
#include "Enum/ChestType.h"

class Game;

class Chest {
protected:
	int cost;

public:
	virtual ~Chest() = default;
	virtual void open(Game& game) = 0;
};

class SeedChest final : public Chest {
public:
	SeedChest();
	void open(Game& game) override;
};

class UtilityChest final : public Chest {
public:
	UtilityChest();
	void open(Game& game) override;
};

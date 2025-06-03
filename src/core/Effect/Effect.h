#pragma once
#include <string>

class Game;

class Effect {
protected:
	std::string name;
	int duration; // 0 = permanent or instant

public:
	virtual ~Effect() = default;
	virtual void applyEffect(Game& game) = 0;
	virtual void removeEffect(Game& game) {} // Optional
};

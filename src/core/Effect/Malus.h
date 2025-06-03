#pragma once
#include "Effect.h"

class Storm : public Effect {
public:
	Storm();
	void applyEffect(Game& game) override;
};

class Frost : public Effect {
public:
	Frost();
	void applyEffect(Game& game) override;
};

class Thief : public Effect {
public:
	Thief();
	void applyEffect(Game& game) override;
};

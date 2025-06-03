class Game;

class AutoClicker {
private:
	int remainingTime;

public:
	void start(int duration);
	void tick(Game& game);
};

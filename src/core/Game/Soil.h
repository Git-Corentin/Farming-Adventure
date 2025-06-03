#pragma once


class Soil {
private:
	int degradationProgress;

public:
	void increase();
	void reset();
	int getDegradationPenalty() const;
};


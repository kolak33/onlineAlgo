#pragma once
#include <random>

class ProbabilityDistribution
{
public:
	ProbabilityDistribution(int iMaxNumber);

	virtual int GetDistribution() = 0;

protected:
	std::random_device m_randDevice;
	std::default_random_engine m_generator;

	int FindPosition(std::vector<double> &vecDistr, double num);
};
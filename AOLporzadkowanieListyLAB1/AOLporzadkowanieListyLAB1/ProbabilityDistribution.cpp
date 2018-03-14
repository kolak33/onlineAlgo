#include "stdafx.h"
#include "ProbabilityDistribution.h"
#include <vector>

ProbabilityDistribution::ProbabilityDistribution(int iMaxNumber)
	: m_generator(m_randDevice())
{
}

int ProbabilityDistribution::FindPosition(std::vector<double> &vecDistr, double num)
{
	for (size_t i = 0; i < vecDistr.size(); ++i)
	{
		if (vecDistr[i] < num) return (i + 1);
	}

	return vecDistr.size() - 1;
}
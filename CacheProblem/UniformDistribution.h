#pragma once
#include "ProbabilityDistribution.h"

class UniformDistribution : public ProbabilityDistribution
{
public:
	UniformDistribution(int iMaxNumber)
		: ProbabilityDistribution(iMaxNumber),
		m_intDistribution(1, 100)
	{
	}

	virtual int GetDistribution()
	{
		return m_intDistribution(m_generator);
	}

protected:
	std::uniform_int_distribution<int> m_intDistribution;
};
#pragma once

#include "ProbabilityDistribution.h"

class HarmonicDistribution : public ProbabilityDistribution
{
public:
	HarmonicDistribution(int iMaxNumber)
		: ProbabilityDistribution(iMaxNumber),
		m_realDistribution(0.0, 1.0)
	{
		CreateHarmonicDistribution(iMaxNumber);
	}

	virtual int GetDistribution();
	std::vector<double>& GetVect()
	{
		return m_harDistr;
	}

protected:
	std::uniform_real_distribution<double> m_realDistribution;
	std::vector<double> m_harDistr; // probability distribution vector

	double ComputeHarmonicNumber(int n);
	void CreateHarmonicDistribution(int n);
};


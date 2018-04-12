#pragma once
#include "ProbabilityDistribution.h"

class DoubleHarmonicDistribution : public ProbabilityDistribution
{
public:
	DoubleHarmonicDistribution(int iMaxNumber)
		: ProbabilityDistribution(iMaxNumber),
		m_realDistribution(0.0, 1.0)
	{
		CreateDoubleHarmonicDistribution(iMaxNumber);
	}

	virtual int GetDistribution();
	std::vector<double>& GetVect()
	{
		return m_doubleHarDistr;
	}

protected:
	std::uniform_real_distribution<double> m_realDistribution;
	std::vector<double> m_doubleHarDistr; // probability distribution vector

	double ComputeDoubleHarmonicNumber(int n);
	void CreateDoubleHarmonicDistribution(int n);
};
#pragma once
#include "ProbabilityDistribution.h"

class GeometricDistribution : public ProbabilityDistribution
{
public:
	GeometricDistribution(int iMaxNumber)
		: ProbabilityDistribution(iMaxNumber),
		m_realDistribution(0.0, 1.0)
	{
		CreateGeometricDistribution(iMaxNumber);
	}

	virtual int GetDistribution();
	std::vector<double>& GetVect()
	{
		return m_geoDistr;
	}

protected:
	std::uniform_real_distribution<double> m_realDistribution;
	std::vector<double> m_geoDistr; // probability distribution vector

	void CreateGeometricDistribution(int n);
};
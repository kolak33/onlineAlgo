#include "stdafx.h"
#include "HarmonicDistribution.h"


int HarmonicDistribution::GetDistribution()
{
	double d = m_realDistribution(m_generator);

	return FindPosition(m_harDistr, d);
}

void HarmonicDistribution::CreateHarmonicDistribution(int n)
{
	double harmonicNum = ComputeHarmonicNumber(n);
	double intervalLength = 1.0;
	for (int i = 0; i < n + 1; ++i)
	{
		double probability = 1.0 / ((double)(i + 1) * harmonicNum);
		intervalLength -= probability;
		m_harDistr.push_back(intervalLength);
	}
}

double HarmonicDistribution::ComputeHarmonicNumber(int n)
{
	double sum = 0.0;
	for (int i = 0; i < n; ++i)
		sum += 1.0 / (i + 1);

	return sum;
}
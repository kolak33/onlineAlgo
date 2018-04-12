#include "stdafx.h"
#include "DoubleHarmonic.h"


int DoubleHarmonicDistribution::GetDistribution()
{
	double d = m_realDistribution(m_generator);

	return FindPosition(m_doubleHarDistr, d);
}

void DoubleHarmonicDistribution::CreateDoubleHarmonicDistribution(int n)
{
	double harmonicNum = ComputeDoubleHarmonicNumber(n);
	double intervalLength = 1.0;
	for (int i = 0; i < n + 1; ++i)
	{
		double probability = 1.0 / ((double)((i + 1) * (i + 1)) * harmonicNum);
		intervalLength -= probability;
		m_doubleHarDistr.push_back(intervalLength);
	}
}

double DoubleHarmonicDistribution::ComputeDoubleHarmonicNumber(int n)
{
	double sum = 0.0;
	for (int i = 0; i < n; ++i)
		sum += 1.0 / ((i + 1) * (i + 1));

	return sum;
}
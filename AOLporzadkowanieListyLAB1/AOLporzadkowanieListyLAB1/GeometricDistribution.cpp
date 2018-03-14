#include "stdafx.h"
#include "GeometricDistribution.h"


int GeometricDistribution::GetDistribution()
{
	double d = m_realDistribution(m_generator);

	return FindPosition(m_geoDistr, d);
}

void GeometricDistribution::CreateGeometricDistribution(int n)
{
	double d = 1.0;
	for (int i = 0; i < n - 1; ++i)
	{
		d *= 0.5;
		m_geoDistr.push_back(d);
	}
	m_geoDistr.push_back(d); // the least one is the same as previous

	d *= 0.5;
	m_geoDistr.push_back(d);
}

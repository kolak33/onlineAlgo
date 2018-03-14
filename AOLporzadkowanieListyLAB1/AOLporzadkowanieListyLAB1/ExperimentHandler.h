#pragma once

#include <vector>
#include <memory>
#include "UniformDistribution.h"
#include "GeometricDistribution.h"
#include "HarmonicDistribution.h"
#include "NoSelfOrganize.h"
#include "MoveToFrondOrganize.h"
#include "TransposeOrganize.h"
#include "CountOrganize.h"

class ExperimentHandler
{
public:
	ExperimentHandler()
	{
		m_testCount = { 100, 500, 1000, 5000 };

		const int iMaxDist = 100;
		m_probabilites = {
			std::make_pair(std::make_shared<UniformDistribution>(iMaxDist), "UniformDistribution"),
			std::make_pair(std::make_shared<GeometricDistribution>(iMaxDist), "Geometry Distribution"),
			std::make_pair(std::make_shared<HarmonicDistribution>(iMaxDist), "Harmonic Distribution") };

		m_organizingLists = {
			std::make_pair(std::make_shared<NoSelfOrginize<Element>>(), "NoSelfOrganize"),
			std::make_pair(std::make_shared<MoveToFrontOrganize<Element>>(), "MoveToFrondOrganize"),
			std::make_pair(std::make_shared<TransposeOrganize<Element>>(), "TransposeOrganize"),
			std::make_pair(std::make_shared<CountOrganize<Element>>(), "CountOrganize")
		};
	}

	void RunTests();

	std::vector<int> m_testCount;
	std::vector<std::pair< std::shared_ptr<ProbabilityDistribution>, std::string> > m_probabilites;
	std::vector<std::pair< std::shared_ptr<SelfOrganizingList<Element>>, std::string> > m_organizingLists;
};
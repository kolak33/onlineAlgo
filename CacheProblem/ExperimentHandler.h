#pragma once

#include <vector>
#include <memory>
#include "UniformDistribution.h"
#include "GeometricDistribution.h"
#include "HarmonicDistribution.h"
#include "DoubleHarmonic.h"
#include "CacheFIFO.h"
#include "CacheFlushWhenFull.h"
#include "CacheLeastRecentlyUsed.h"
#include "CacheLeastFrequentlyUsed.h"
#include "CacheRandom.h"
#include "CacheRandomizedMarkup.h"

class ExperimentHandler
{
public:
	ExperimentHandler()
	{
		m_testCount = 10000;
		m_amountOfPages = { 20, 30, 40, 50, 60, 70, 80, 90, 100 }; // 20 .. 100
		
		m_cachePageAmountDivider = { 10, 9, 8, 7, 6, 5, 4, 3, 2 }; // 10 .. 5

		const int iMaxDist = 100;
		m_probabilites = {
			std::make_pair(std::make_shared<UniformDistribution>(iMaxDist), "UniformDistribution"),
			std::make_pair(std::make_shared<GeometricDistribution>(iMaxDist), "GeometryDistribution"),
			std::make_pair(std::make_shared<HarmonicDistribution>(iMaxDist), "HarmonicDistribution"),
			std::make_pair(std::make_shared<DoubleHarmonicDistribution>(iMaxDist), "DoubleHarmonicDistribution") 
		};

		m_cacheOrganizationStrategies = {
			std::make_pair(std::make_shared<CacheFIFO>(), "CacheFIFO"),
			std::make_pair(std::make_shared<CacheFlushWhenFull>(), "CacheFlushWhenFull"),
			std::make_pair(std::make_shared<CacheLeastRecentlyUsed>(), "CacheLeastRecentlyUsed"),
			std::make_pair(std::make_shared<CacheLeastFrequentlyUsed>(), "CacheLeastFrequentlyUsed"),
			std::make_pair(std::make_shared<CacheRandom>(), "CacheRandom"),
			std::make_pair(std::make_shared<CacheRandomizedMarkup>(), "CacheRandomizedMarkup")
		};
	}

	void RunTests();

	int m_testCount; // num of tests
	std::vector<int> m_cachePageAmountDivider; // cache k = n / divider; and here we have array of dividers
	std::vector<int> m_amountOfPages; // n
	std::vector<std::pair< std::shared_ptr<ProbabilityDistribution>, std::string> > m_probabilites;
	std::vector<std::pair< std::shared_ptr<CacheBase>, std::string> > m_cacheOrganizationStrategies;
};
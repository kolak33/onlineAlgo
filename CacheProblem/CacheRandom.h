#pragma once
#include "CacheBase.h"

#include <set>
#include <random>

class CacheRandom : public CacheBase
{
public:
	CacheRandom();

	virtual int FindPage(int pageNum);
	virtual void EmptyCache();
	virtual void SetCacheSize(int size);

protected:
	virtual void CacheReorganize(int pageNum);

	std::set<int> m_cache;
	std::random_device m_randDevice;
	std::default_random_engine m_generator;
	std::uniform_int_distribution<int> m_intDistribution;
};


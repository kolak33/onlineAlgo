#pragma once
#include "CacheBase.h"

#include <set>
#include <random>

class CacheRandomizedMarkup : public CacheBase
{
public:
	CacheRandomizedMarkup();

	virtual int FindPage(int pageNum);
	virtual void EmptyCache();
	virtual void SetCacheSize(int size);

protected:
	virtual void CacheReorganize(int pageNum);
	void SetDistributionSize(int size);

	std::set<int> m_cache;
	std::set<int> m_markedPages;
	std::set<int> m_notMarkedPages;
	std::random_device m_randDevice;
	std::default_random_engine m_generator;
	std::uniform_int_distribution<int> m_intDistribution;
};
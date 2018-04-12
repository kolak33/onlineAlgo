#include "stdafx.h"
#include "CacheRandom.h"


CacheRandom::CacheRandom()
	: CacheBase(),
	m_generator(m_randDevice())
{
}

void CacheRandom::CacheReorganize(int pageNum)
{
	if (m_cache.size() < m_cacheMaxSize)
		m_cache.insert(pageNum);
	else
	{
		int posToDelete = m_intDistribution(m_generator) - 1;
		decltype(m_cache)::iterator iter = m_cache.begin();
		std::advance(iter, posToDelete);
		m_cache.erase(iter);
		m_cache.insert(pageNum);
	}
}

//return cost of operation:
// 0 if page was in cache
// 1 otherwise
int CacheRandom::FindPage(int pageNum)
{
	if (std::find(m_cache.begin(), m_cache.end(), pageNum) == m_cache.end()) //page not found
	{
		CacheReorganize(pageNum);
		return 1;
	}
	return 0;
}

void CacheRandom::EmptyCache()
{
	m_cache.clear();
}

void CacheRandom::SetCacheSize(int size)
{
	__super::SetCacheSize(size);
	// change distribution max number 
	std::uniform_int_distribution<int> newDistribution(1, size);
	m_intDistribution = newDistribution;
}
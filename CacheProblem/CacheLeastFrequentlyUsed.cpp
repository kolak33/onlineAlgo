#include "stdafx.h"
#include "CacheLeastFrequentlyUsed.h"
#include <algorithm>

CacheLeastFrequentlyUsed::CacheLeastFrequentlyUsed()
	: CacheBase()
{
	m_allPagesCounter.resize(101, 0);
}

void CacheLeastFrequentlyUsed::CacheReorganize(int pageNum)
{
	if (m_cache.size() < m_cacheMaxSize)
	{
		m_cache.push_back(pageNum);
	}
	else
	{
		auto minCounterIter = std::min_element(m_cachePageCounter.begin(), m_cachePageCounter.end(),
			[](decltype(m_cachePageCounter)::value_type& l, decltype(m_cachePageCounter)::value_type& r) -> bool { return l.second < r.second; });

		int pageNumToDelete = minCounterIter->first;
		auto pageToDelIter = find(m_cache.begin(), m_cache.end(), pageNumToDelete); // must be in array
		m_cache.erase(pageToDelIter);
		m_cache.push_back(pageNum);

		m_cachePageCounter.erase(minCounterIter);
	}

	m_allPagesCounter[pageNum]++;
	m_cachePageCounter[pageNum] = m_allPagesCounter[pageNum];
}

//return cost of operation:
// 0 if page was in cache
// 1 otherwise
int CacheLeastFrequentlyUsed::FindPage(int pageNum)
{
	if (std::find(m_cache.begin(), m_cache.end(), pageNum) == m_cache.end()) //page not found
	{
		CacheReorganize(pageNum);
		return 1;
	}
	else
	{
		m_allPagesCounter[pageNum]++;
		m_cachePageCounter.find(pageNum)->second = m_allPagesCounter[pageNum]; // update cachePageCounter
		return 0;
	}
}

void CacheLeastFrequentlyUsed::EmptyCache()
{
	m_cache.clear();
	m_allPagesCounter.assign(101, 0);
	m_cachePageCounter.clear();
}
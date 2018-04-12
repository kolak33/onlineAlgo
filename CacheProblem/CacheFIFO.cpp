#include "stdafx.h"
#include "CacheFIFO.h"


CacheFIFO::CacheFIFO()
	: CacheBase()
{
}

void CacheFIFO::CacheReorganize(int pageNum)
{
	if (m_cache.size() < m_cacheMaxSize)
		m_cache.push_back(pageNum);
	else
	{
		m_cache.pop_front();
		m_cache.push_back(pageNum);
	}
}

//return cost of operation:
// 0 if page was in cache
// 1 otherwise
int CacheFIFO::FindPage(int pageNum)
{
	if (std::find(m_cache.begin(), m_cache.end(), pageNum) == m_cache.end()) //page not found
	{
		CacheReorganize(pageNum);
		return 1;
	}
	return 0;
}

void CacheFIFO::EmptyCache()
{
	m_cache.clear();
}
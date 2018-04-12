#include "stdafx.h"
#include "CacheFlushWhenFull.h"


CacheFlushWhenFull::CacheFlushWhenFull()
	: CacheBase()
{
}

void CacheFlushWhenFull::CacheReorganize(int pageNum)
{
	if (m_cache.size() < m_cacheMaxSize)
		m_cache.push_back(pageNum);
	else
	{
		EmptyCache();
		m_cache.push_back(pageNum);
	}
}

//return cost of operation:
// 0 if page was in cache
// 1 otherwise
int CacheFlushWhenFull::FindPage(int pageNum)
{
	if (std::find(m_cache.begin(), m_cache.end(), pageNum) == m_cache.end()) //page not found
	{
		CacheReorganize(pageNum);
		return 1;
	}
	return 0;
}

void CacheFlushWhenFull::EmptyCache()
{
	m_cache.clear();
}

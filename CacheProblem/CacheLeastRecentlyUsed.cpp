#include "stdafx.h"
#include "CacheLeastRecentlyUsed.h"


CacheLeastRecentlyUsed::CacheLeastRecentlyUsed()
	: CacheBase()
{
}


void CacheLeastRecentlyUsed::CacheReorganize(int pageNum)
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
// recently used page is in the back
// least recently used page is in the front 
int CacheLeastRecentlyUsed::FindPage(int pageNum)
{
	auto foundIter = std::find(m_cache.begin(), m_cache.end(), pageNum);
	if (foundIter == m_cache.end()) //page not found
	{
		CacheReorganize(pageNum);
		return 1;
	}
	else // page found, move to back
	{
		m_cache.erase(foundIter);
		m_cache.push_back(pageNum);
		return 0;
	}
}

void CacheLeastRecentlyUsed::EmptyCache()
{
	m_cache.clear();
}

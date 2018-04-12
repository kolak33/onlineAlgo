#include "stdafx.h"
#include "CacheRandomizedMarkup.h"


CacheRandomizedMarkup::CacheRandomizedMarkup()
	: CacheBase()
{
}

void CacheRandomizedMarkup::CacheReorganize(int pageNum)
{
	if (m_cache.size() < m_cacheMaxSize)
	{
		m_cache.insert(pageNum);
		//m_markedPages.insert(pageNum);
	}
	else
	{
		/*if (m_markedPages.size() == m_cache.size()) //all elements are marked
		{
			m_markedPages.clear(); //uncheck all
		}
		int uncheckedPagesCount = m_cache.size() - m_markedPages.size();
		SetDistributionSize(uncheckedPagesCount);
		int posToDelete = m_intDistribution(m_generator) - 1;
		decltype(m_markedPages)::iterator iter = m_markedPages.begin();
		std::advance(iter, posToDelete);
		
		auto cachePageToDelIter = m_cache.find(*iter);
		m_cache.erase(cachePageToDelIter); // delete from cache
		m_markedPages.erase(iter); // delete from marked pages

		m_cache.insert(pageNum); // add to cache
		m_markedPages.insert(pageNum); // mark page */

		if (m_cache.size() == m_cacheMaxSize && m_notMarkedPages.size() == 0) // all elements are marked
		{
			m_notMarkedPages = m_cache; //uncheck all elements
		}
		int uncheckedPagesCount = m_notMarkedPages.size();
		SetDistributionSize(uncheckedPagesCount);
		int posToDelete = m_intDistribution(m_generator) - 1;
		decltype(m_notMarkedPages)::iterator iter = m_notMarkedPages.begin();
		std::advance(iter, posToDelete);

		auto cachePageToDelIter = m_cache.find(*iter);
		if (cachePageToDelIter == m_cache.end())
			int a = 5;
		m_cache.erase(cachePageToDelIter); // delete from cache
		m_cache.insert(pageNum); // insert new page
		m_notMarkedPages.erase(iter); // this position was thrown out of cache just before
	}
}

//return cost of operation:
// 0 if page was in cache
// 1 otherwise
int CacheRandomizedMarkup::FindPage(int pageNum)
{
	if (std::find(m_cache.begin(), m_cache.end(), pageNum) == m_cache.end()) //page not found
	{
		CacheReorganize(pageNum);
		return 1;
	}
	else // page found, mark page if not already marked
	{
	/*	if (m_markedPages.find(pageNum) == m_markedPages.end())
			m_markedPages.insert(pageNum);*/
		auto notMarkedIter = m_notMarkedPages.find(pageNum);
		if (notMarkedIter != m_notMarkedPages.end()) // mark page if not already marked
		{
			m_notMarkedPages.erase(notMarkedIter);
		}
	}
	return 0;
}

void CacheRandomizedMarkup::EmptyCache()
{
	m_cache.clear();
	m_notMarkedPages.clear();
}

void CacheRandomizedMarkup::SetDistributionSize(int size)
{
	std::uniform_int_distribution<int> newDistribution(1, size);
	m_intDistribution = newDistribution;
}

void CacheRandomizedMarkup::SetCacheSize(int size)
{
	__super::SetCacheSize(size);
	// change distribution max number 
	SetDistributionSize(size);
}


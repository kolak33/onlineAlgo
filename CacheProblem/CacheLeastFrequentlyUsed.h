#pragma once
#include "CacheBase.h"

#include <vector>
#include <map>

class CacheLeastFrequentlyUsed : public CacheBase
{
public:
	CacheLeastFrequentlyUsed();

	virtual int FindPage(int pageNum);
	virtual void EmptyCache();

protected:
	virtual void CacheReorganize(int pageNum);

	std::vector<int> m_cache;
	std::vector<int> m_allPagesCounter; // counts number of usage of all pages
	std::map<int, int> m_cachePageCounter; // has counter only for cache pages
};

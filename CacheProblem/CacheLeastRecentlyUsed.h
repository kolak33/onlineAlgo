#pragma once
#include "CacheBase.h"

#include <deque>

class CacheLeastRecentlyUsed : public CacheBase
{
public:
	CacheLeastRecentlyUsed();
	virtual int FindPage(int pageNum);
	virtual void EmptyCache();

protected:
	virtual void CacheReorganize(int pageNum);

	std::deque<int> m_cache;
};


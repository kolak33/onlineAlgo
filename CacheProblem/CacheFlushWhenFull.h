#pragma once
#include "CacheBase.h"
#include <vector>

class CacheFlushWhenFull : public CacheBase
{
public:
	CacheFlushWhenFull();

	virtual int FindPage(int pageNum);
	virtual void EmptyCache();

protected:
	virtual void CacheReorganize(int pageNum);

	std::vector<int> m_cache;
};


#pragma once

//template <template <typename Type, typename...> class ContainerType = std::vector>
class CacheBase
{
public:
	CacheBase();
	
	virtual int FindPage(int pageNum) = 0;
	virtual void EmptyCache() = 0;
	virtual void SetCacheSize(int size);
	
protected:
	virtual void CacheReorganize(int pageNum) = 0; //adds page to cache

	int m_cacheMaxSize;
};

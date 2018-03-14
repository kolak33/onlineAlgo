#pragma once

#include "SelfOrganizingList.h"

template<class Elem>
class CountOrganize : public SelfOrganizingList<Elem>
{
public:
	CountOrganize()
	{
	}

	virtual void SelfOrganize(typename std::vector<Elem>::iterator it = nullptr);
};

template<class Elem>
void CountOrganize<Elem>::SelfOrganize(typename std::vector<Elem>::iterator it)
{
	it->m_iCount++;
	while (it != this->m_list.begin() && it->m_iCount > (std::prev(it))->m_iCount)
	{
		std::iter_swap(it, it - 1);
		it--;
	}
}

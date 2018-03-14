#pragma once

#include <vector>
#include <algorithm>
#include <boost\bind.hpp>

class Element
{
public:
	Element(int iNum)
		: m_iNum(iNum),
		m_iCount(0)
	{
	}

	int m_iNum;
	int m_iCount;
};

template<class Elem>
class SelfOrganizingList
{
public:
	SelfOrganizingList()
	{
	}

	int Access(int iNumber);
	void EmptyList();
protected:
	typename std::vector<Elem> m_list;

	virtual void SelfOrganize(typename std::vector<Elem>::iterator it = nullptr) = 0;
};

template<class Elem>
void SelfOrganizingList<Elem>::EmptyList()
{
	m_list.clear();
}

template<class Elem>
int SelfOrganizingList<Elem>::Access(int iNumber)
{
	std::vector<Elem>::iterator it = std::find_if(m_list.begin(), m_list.end(),
		boost::bind(&Element::m_iNum, _1) == iNumber);

	if (it == m_list.end()) // not found, add Elem at the end of the list
	{
		m_list.push_back(Elem(iNumber));
		return m_list.size();
	}
	else
	{
		int iElemPosition = std::distance(m_list.begin(), it);
		SelfOrganize(it);
		return iElemPosition + 1;
	}
}

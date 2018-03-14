#pragma once

#include "SelfOrganizingList.h"

template<class Elem>
class TransposeOrganize : public SelfOrganizingList<Elem>
{
public:
	TransposeOrganize()
	{
	}

	virtual void SelfOrganize(typename std::vector<Elem>::iterator it = nullptr);
};

template<class Elem>
void TransposeOrganize<Elem>::SelfOrganize(typename std::vector<Elem>::iterator it)
{
	if (it != this->m_list.begin())
		std::iter_swap(it, it - 1); //same as: std::swap(*it, *(it - 1));
}

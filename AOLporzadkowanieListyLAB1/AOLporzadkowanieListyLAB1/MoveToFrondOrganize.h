#pragma once

#include "SelfOrganizingList.h"

template<class Elem>
class MoveToFrontOrganize : public SelfOrganizingList<Elem>
{
public:
	MoveToFrontOrganize()
	{
	}

	virtual void SelfOrganize(typename std::vector<Elem>::iterator it = nullptr);
};

template<class Elem>
void MoveToFrontOrganize<Elem>::SelfOrganize(typename std::vector<Elem>::iterator it)
{
	std::rotate(this->m_list.begin(), it, it + 1); // move first element to the beginning
}

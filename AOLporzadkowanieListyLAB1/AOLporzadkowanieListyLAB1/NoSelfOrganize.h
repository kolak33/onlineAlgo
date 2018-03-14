#pragma once

#include "SelfOrganizingList.h"

template<class Elem>
class NoSelfOrginize : public SelfOrganizingList<Elem>
{
public:
	NoSelfOrginize()
	{
	}

	virtual void SelfOrganize(typename std::vector<Elem>::iterator it = nullptr)
	{
	}
};
#ifndef __MANAGER_H__
#define __MANAGER_H__

#include "stdafx.h"
#include "Config.h"
#include "List.h"

template <typename T>
class Manager
{
private:
    List<T> * m_pT;

public:
	Manager()
	{
		m_pT = new List<T>();
	}

	List<T> * GetList()
	{
		if (m_pT == NULL)
			return NULL;
		return m_pT;
	}

	void Add(T t)
	{
		this->GetList()->Add(t);
	}
};

#endif
#pragma once
#include "TArrayTable.h"

class TScanTable:public TArrayTable
{
public:
	TScanTable(int _size = 10):TArrayTable(_size){}
	bool Find(TKey key)
	{
		for (int i = 0; i < DataCount; i++)
		{
			if (mas[i] == key)
			{
				curr = i;
				return true;
			}
			Eff++;
		}
		curr = DataCount;
		return false;
	}

	bool Insert(TRecord rec)
	{
		if (IsFull())
			return false;
		if (Find(rec.key))
			return false;
		mas[curr] = rec;
		DataCount++;
		Eff++;
		return true;
	}

	bool Delete(TKey key)
	{
		if (IsEmpty()) 
			return false;
		if (!Find(key)) 
			return false;
		mas[curr] = mas[DataCount - 1];
		DataCount--;
		Eff++;
		return true;
	}
};
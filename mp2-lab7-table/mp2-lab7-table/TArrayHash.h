#pragma once

#include "THashTable.h"

class TArrayHash : public THashTable
{
	TRecord* mas;
	int size, step, curr;
	TRecord free, del;
public:
	TArrayHash(int _size = 100, int _step = 7)
	{
		mas = new TRecord[_size];
		size = _size;
		step = _step;
		free.key = -1; del.key = -2;
		for (int i = 0; i < size; i++)
			mas[i] = free;
	}

	~TArrayHash() { delete[] mas; }

	bool Find(TKey key)
	{
		int pos = HashFunc(key) % size;
		int DelPos;
		bool res = false;
		for (int i = 0; i < size; i++)
		{
			if (mas[pos] == free)
				break;
			else if (mas[pos].key == key)
			{
				res = true;
				curr = pos;
				break;
			}
			else if (mas[pos] == del && DelPos == -1)
			{
				DelPos = pos; 
				curr = pos;
			}
			pos = (pos + step) % size;
		}
		if ((DelPos != 1) && (res == false))
			curr = DelPos;
		return res;
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
		mas[curr] = del;
		DataCount--;
		Eff++;
		return true;
	}

	void Reset()
	{
		for (curr = 0; curr < size; curr++)
			if (!(mas[curr] == free) && !(mas[curr] == del))
				return;
	}

	bool GoNext() 
	{
		while (mas[curr] == del || mas[curr] == free)
			curr++;
	}

	bool IsFull() const
	{
		return DataCount == size;
	}

	bool IsEnd()
	{
		return curr == DataCount; //??
	}
};
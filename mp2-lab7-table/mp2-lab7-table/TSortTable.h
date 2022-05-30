#pragma once
#include "TArrayTable.h"
#include "TScanTable.h"
class TSortTable : public TArrayTable
{
	void Sort(int f, int l)
	{
		int k = (f + l) / 2;
		int m = mas[k].key;
		int i = f, j = l;
		while (i < j)
		{
			while (mas[i].key < m)
			{
				i++; Eff++;
			}
			while (mas[j].key > m)
			{
				j--; Eff++;
			}
			if (i <= j)
			{
				swap(mas[i], mas[j]);
				Eff++;
				i++; j--;
			}
		}
		if (f < i)
			Sort(f, j);
		if (i < l)
			Sort(i, l);
	}
public:
	TSortTable(int size = 100) : TArrayTable(size) {}
	TSortTable(const TScanTable& st) :TArrayTable(st.GetSize())
	{
		for (int i = 0; i < st.GetSize(); i++)
			mas[i] = st.GetCurrRec();
		Sort(0, DataCount); //?
	}
	bool Find(TKey key)
	{
		int left = 0; int right = DataCount - 1;
		int mid;
		while (left<=right)
		{
			Eff++;
			mid = (left + right) / 2;
			if (mas[mid].key < key)
				left = mid + 1;
			else if (mas[mid].key > key)
				right = mid - 1;
			else
			{
				curr = mid;
				return true;
			}
		}
		curr = left;
		return false;
	}

	bool Insert(TRecord rec)
	{
		if (IsFull() || Find(rec.key))
			return false;
		for (int i = DataCount-1; i >= curr; i--)
		{
			Eff++;
			mas[i + 1] = mas[i];
		}
		mas[curr] = rec;
		Eff++;
		DataCount++;
		return true;
	}

	bool Delete(TKey key)
	{
		if (IsEmpty())
			return false;
		if (!Find(key))
			return false;
		for (int i = curr; i < DataCount - 1; i++)
		{
			mas[i] = mas[i + 1];
			Eff++;
		}
		DataCount--;
		return true;
	}
};
#pragma once
#include "TTable.h"
#include <iostream>
using namespace std;
class TArrayTable:public TTable 
{
protected:
	TRecord* mas;
	int size, curr;
public:
	TArrayTable(int _size = 10)
	{
		size = _size;
		curr = 0;
		mas = new TRecord[size];
	}

	~TArrayTable()
	{
		delete[] mas;
	}

	bool IsFull() const
	{
		return DataCount == size;
	}

	void Reset() {curr = 0;}
	bool GoNext() { curr++; return true; }
	bool IsEnd() { return curr == DataCount; }
	int GetSize() const { return size; }
	TRecord GetCurrRec() const { return mas[curr]; }
	void Print()
	{
		for (Reset(); !IsEnd(); GoNext())
			cout << mas[curr].key << mas[curr].val << endl;
	}
};

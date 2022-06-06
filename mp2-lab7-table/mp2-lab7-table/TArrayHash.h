#pragma once

#include "THashTable.h"

class TArrayHash : public THashTable
{
	TRecord* mas;
	int size, step;
	mutable int curr;
	TRecord free, del;
public:
	/*TArrayHash(int _size=100, int _step=7) : mas(new TRecord[_size]), size(_size), step(_step)
	{
		free.key = -1;
		del.key = -2;
		for (int i = 0; i < size; ++i)
		{
			mas[i] = free;
		}
	}
	~TArrayHash() { delete[] mas; }
	int GetSize() const { return size; }
	TRecord GetCurrRec() const
	{
		return mas[curr];
	}
	bool Find(TKey key)
	{
		int pos = HashFunc(key) % size, delpos = -1;
		bool res = false;
		for (int i = 0; i < size; i++, Eff++)
		{
			if (mas[pos] == free)
			{
				curr = pos;
				break;
			}
			else if (mas[pos].key == key)
			{
				curr = pos;
				res = true;
				break;
			}
			else if (mas[pos] == del && delpos == -1)
			{
				delpos = pos;
				curr = pos;
			}
			pos = (pos + step) % size;
		}
		if (delpos != -1 && res == false)
		{
			curr = delpos;
		}
		return res;
	}
	bool Insert(TRecord rec)
	{
		if (IsFull() || Find(rec.key))
		{
			return false;
		}
		mas[curr] = rec;
		DataCount++;
		Eff++;
		return true;
	}
	bool Delete(TKey key) 
	{
		if (IsEmpty() || !Find(key))
			return false;
		mas[curr] = del;
		DataCount--;
		Eff++;
		return true;
	}
	void Reset()
	{
		curr = 0;
	}
	bool GoNext()
	{
		if (!(mas[curr] == del) && !(mas[curr] == free))
		{
			curr++;
		}

		while (mas[curr] == del || mas[curr] == free)
			curr++;
		return true;
	}
	bool IsFull() const
	{
		return DataCount == size;
	}
	bool IsEnd()
	{
		return curr == DataCount;
	}*/

	/*TArrayHash(int size = 10, int step = 7) : size(size), step(step) {
		mas = new TRecord[size];

		free.key = -1;
		del.key = -2;

		for (int i = 0; i < size; i++) {
			mas[i] = free;
		}
	}

	~TArrayHash() { delete[] mas; }

	bool IsFull() const {
		for (int i = 0; i < size; i++) {
			if (mas[i] == free || mas[i] == del) {
				return false;
			}
		}
		return true;
	}

	TRecord GetCurrRec() const {
		return mas[curr];
	}

	void Reset() {
		for (curr = 0; curr < size; curr++) {
			if (!(mas[curr] == free) && !(mas[curr] == del)) return;
		}
	}

	bool IsEnd() { return curr == size; }

	bool GoNext() {
		for (curr++; curr < size - 1; curr++) {
			if (!(mas[curr] == free) && !(mas[curr] == del)) return true;
		}
		return true;
	}

	bool Find(TKey key) {
		int n = HashFunc(key);
		n %= size;
		int delPosition = -1;

		for (int i = 0; i < size; i++) {
			if (mas[n] == free) {
				curr = n;
				return false;
			}
			else if (mas[n].key == key) {
				curr = n;
				return true;
			}
			else if (mas[i] == del && delPosition == -1) {
				delPosition = n;
				curr = n;
			}
			n = (n + step) % size;
		}

		if (delPosition != -1) {
			curr = delPosition;
		}
		return false;
	}

	bool Insert(TRecord rec) {
		if (IsFull()) return false;
		if (Find(rec.key)) return false;

		mas[curr] = rec;
		DataCount++;
		Eff++;
		return true;
	}

	bool Delete(TKey key) {
		if (IsEmpty()) return false;
		if (!Find(key)) return false;

		for (Reset(); !IsEnd(); GoNext()) {
			if (mas[curr].key == key) {
				mas[curr] = del;
			}
			Eff++;
		}

		DataCount--;
		return true;
	}*/

	public:
		TArrayHash(int size = 10, int step = 7) : size(size), step(step) {
			mas = new TRecord[size];

			free.key = -1;
			del.key = -2;

			for (int i = 0; i < size; i++) {
				mas[i] = free;
			}
		}

		~TArrayHash() { delete[] mas; }

		bool IsFull() const {
			for (int i = 0; i < size; i++) {
				if (mas[i] == free || mas[i] == del) {
					return false;
				}
			}
			return true;
		}

		TRecord GetCurrRec() const {
			return mas[curr];
		}

		void Reset() {
			for (curr = 0; curr < size; curr++) {
				if (!(mas[curr] == free) && !(mas[curr] == del)) return;
			}
		}

		bool IsEnd() { return curr == size; }

		bool GoNext() {
			for (curr++; curr < size; curr++) {
				if (!(mas[curr] == free) && !(mas[curr] == del)) return true;
			}
			return true;
		}

		bool Find(TKey key) {
			int pos = HashFunc(key) % size, delpos = -1;
			bool res = false;
			for (int i = 0; i < size; ++i, Eff++)
			{
				if (mas[pos] == free)
				{
					curr = pos;
					break;
				}
				else if (mas[pos].key == key)
				{
					curr = pos;
					res = true;
					break;
				}
				else if (mas[pos] == del && delpos == -1)
				{
					delpos = pos;
					curr = pos;
				}
				pos = (pos + step) % size;
			}
			if (delpos != -1 && res == false)
			{
				curr = delpos;
			}
			return res;
		}

		bool Insert(TRecord rec) {
			if (IsFull()) return false;
			if (Find(rec.key)) return false;

			mas[curr] = rec;
			DataCount++;
			Eff++;
			return true;
		}

		bool Delete(TKey key) {
			if (IsEmpty()) return false;
			if (!Find(key)) return false;

			mas[curr] = del;
			DataCount--;
			Eff++;
			return true;
		}

};
#pragma once

#include "THashTable.h"
#include <iostream>
using namespace std;
class TArrayHash : public THashTable
{
	TRecord* mas;
	int size, step;
	mutable int curr;
	TRecord free, del;
public:
    TArrayHash(int _size = 100, int _step = 7)
    {
        size = _size;
        step = _step;
        mas = new TRecord[size];
        free.key = -1;
        del.key = -2;
        for (int i = 0; i < size; ++i)
        {
            mas[i] = free;
        }
    }
    ~TArrayHash()
    {
        delete[] mas;
    }
    //int GetSize() { return size; }
    
    bool Find(TKey key)
    {
        int pos = HashFunc(key) % size, delPos = -1;
        bool res = false;
        for (int i = 0; i < size; i++) {
            Eff++;
            if (mas[pos] == free) {
                curr = pos;
                break;
            }
            else if (mas[pos].key == key) {
                curr = pos;
                res = true;
                break;
            }
            else if (mas[pos] == del && delPos == -1) {
                delPos = pos;
                curr = pos;
            }
            pos = (pos + step) % size;
        }
        if (delPos != -1 && res == false) {
            curr = delPos;
        }
        return res;
    }
    bool Insert(TRecord rec)
    {
        if (IsFull() || Find(rec.key)) {
            return false;
        }
        mas[curr] = rec;
        DataCount++;
        Eff++;
        return true;
    }

    bool Delete(TKey key)
    {
        if (IsEmpty() || !Find(key)) {
            return false;
        }
        mas[curr] = del;
        DataCount--;
        Eff++;
        return true;
    }
    void Reset()
    {
        for (curr = 0; curr < size; curr++) {
            if (!(mas[curr] == free) && !(mas[curr] == del)) {
                return;
            }
        }
    }
    bool GoNext()
    {
        for (curr++; curr < size; curr++) {
            if (!(mas[curr] == free) && !(mas[curr] == del)) {
                return true;
            }
        }
        return true;
    }
    bool IsEnd()
    {
        return curr == size;
    }

    TRecord GetCurrRec() const {
        return mas[curr];
    }
    bool IsFull() const
    {
        for (int i = 0; i < size; i++) {
            if (mas[i] == free || mas[i] == del) {
                return false;
            }
        }
        return true;
    }

    /*void Print(ostream& os)
    {
        for (Reset(); !IsEnd(); GoNext()) {
            os << mas[curr] << endl;
        }
        Reset();
        os << endl;
    }*/
	/*public:
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
			for (int i = 0; i < size; i++)
			{
				Eff++;
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
		}*/


//public:
//	TArrayHash(int _size = 100, int _step = 7)
//	{
//		size = _size;
//		step = _step;
//		mas = new TRecord[size];
//		free.key = -1;
//		del.key = -2;
//		for (int i = 0; i < size; ++i)
//		{
//			mas[i] = free;
//		}
//	}
//	~TArrayHash()
//	{
//		delete[] mas;
//	}
//	int GetSize() { return size; }
//	TRecord GetCurrRec() const
//	{
//		return mas[curr];
//	}
//	bool Find(TKey key)
//	{
//		int pos = HashFunc(key) % size, delPos = -1;
//		bool res = false;
//		for (int i = 0; i < size; i++) {
//			Eff++;
//			if (mas[pos] == free) {
//				curr = pos;
//				break;
//			}
//			else if (mas[pos].key == key) {
//				curr = pos;
//				res = true;
//				break;
//			}
//			else if (mas[pos] == del && delPos == -1) {
//				delPos = pos;
//				curr = pos;
//			}
//			pos = (pos + step) % size;
//		}
//		if (delPos != -1 && res == false) {
//			curr = delPos;
//		}
//		return res;
//	}
//	bool Insert(TRecord rec)
//	{
//		if (IsFull() || Find(rec.key)) {
//			return false;
//		}
//		mas[curr] = rec;
//		DataCount++;
//		Eff++;
//		return true;
//	}
//
//	bool Delete(TKey key)
//	{
//		if (IsEmpty() || !Find(key)) {
//			return false;
//		}
//		mas[curr] = del;
//		DataCount--;
//		Eff++;
//		return true;
//	}
//	void Reset()
//	{
//		for (curr = 0; curr < size; curr++) {
//			if (!(mas[curr] == free) && !(mas[curr] == del)) {
//				return;
//			}
//		}
//	}
//	bool GoNext()
//	{
//		for (curr++; curr < size; curr++) {
//			if (!(mas[curr] == free) && !(mas[curr] == del)) {
//				return true;
//			}
//		}
//		return true;
//	}
//	bool IsEnd()
//	{
//		return curr == size;
//	}
//
//	TRecord GetCurrRec() {
//		return mas[curr];
//	}
//	bool IsFull() const
//	{
//		for (int i = 0; i < size; i++) {
//			if (mas[i] == free || mas[i] == del) {
//				return false;
//			}
//		}
//		return true;
//	}


};
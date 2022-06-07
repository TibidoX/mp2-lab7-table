#pragma once
#include <string>
#include <iostream>
using namespace std;

typedef int TKey;
typedef std::string TValue;

struct TRecord
{
	TKey key;
	TValue val;

public:
	TRecord(/*TKey _key, TValue _val*/)
	{
		//key = _key;
		//val = _val;
	}
	TRecord(TKey _key, TValue _val)
	{
		key = _key;
		val = _val;
	}
	bool operator >(TKey& _key)
	{
		return key > _key;
	}

	bool operator <(TKey& _key)
	{
		return key < _key;
	}

	bool operator >=(TKey& _key)
	{
		return key >= _key;
	}

	bool operator<=(TKey& _key)
	{
		return key <= _key;
	}

	bool operator==(TKey& _key)
	{
		return key == _key;
	}

	bool operator==(const TRecord& rec)
	{
		return (key == rec.key && val == rec.val);
	}
};

class TTable
{
protected:
	int DataCount, Eff;
public:
	TTable()
	{
		DataCount = 0;
		Eff = 0;
	}

	virtual ~TTable() {}
	virtual int GetDataCount() const
	{
		return DataCount;
	}

	virtual int GetEff() const
	{
		return Eff;
	}

	virtual void ClearEff()
	{
		Eff = 0;
	}

	virtual void Clear()
	{
		DataCount = 0;
	}

	virtual bool IsEmpty() const
	{
		return DataCount == 0;
	}

	virtual bool IsFull() const = 0;
	virtual bool Find(TKey key) = 0;
	virtual bool Insert(TRecord rec) = 0;
	virtual bool Delete(TKey key) = 0;
	virtual void Reset() = 0;
	virtual bool IsEnd() = 0;
	virtual bool GoNext() = 0;
	virtual TRecord GetCurrRec() const = 0;
	virtual void Print(ostream& os)
	{
		for (Reset(); !IsEnd(); GoNext())
			os << GetCurrRec().key << ' ' << GetCurrRec().val << endl;
	}

	friend std::ostream& operator<<(std::ostream& os, TTable& t)
	{
		t.Print(os);
		return os;
	}
};
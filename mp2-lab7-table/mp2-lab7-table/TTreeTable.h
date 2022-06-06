#pragma once
#include "TTable.h"
#include "TNode.h"
#include <iostream>
#include "TStack.h"
using namespace std;
class TTreeTable:public TTable
{
protected:
	TNode* pRoot, * pCurr, * pPrev;
	TStack<TNode*> st;
	int currPos;
public:
	TTreeTable()
	{
		pRoot = nullptr;
		pCurr = nullptr;
		pPrev = nullptr;
		currPos = 0;
	}

	~TTreeTable() { DelTree(pRoot); }

	bool Find(TKey key)
	{
		pCurr = pRoot;
		pPrev = nullptr;
		while (pCurr != nullptr)
		{
			Eff++;
			if (pCurr->rec.key == key)
			{
				return true;
			}
			pPrev = pCurr;
			if (pCurr->rec.key > key)
			{
				pCurr = pCurr->pL;
			}
			else
			{
				pCurr = pCurr->pR;
			}
		}
		pCurr = pPrev;
		return false;
	}

	bool Insert(TRecord rec)
	{
		//if (Find(rec.key))
		//	return false;
		//TNode* tmp = new TNode(rec);
		//if (IsEmpty()) //??
		//{
		//	pRoot = tmp;
		//}
		//else
		//{
		//	if (rec.key > pCurr->rec.key)
		//		pCurr->pR = tmp;
		//	else
		//		pCurr->pL = tmp;
		//	DataCount++;
		//	Eff++;
		//	return true;
		//}

		if (Find(rec.key)) return false;

		TNode* tmp = new TNode(rec);

		if (IsEmpty()) {
			pRoot = tmp;
		}
		else {
			if (rec.key > pCurr->rec.key) {
				pCurr->pR = tmp;
			}
			else {
				pCurr->pL = tmp;
			}
		}

		DataCount++;
		return true;
	}

	bool Delete(TKey key)
	{
		if (!Find(key))
			return false;
		TNode* tmp = pCurr;
		if (pCurr->pR == nullptr)
		{
			if (pPrev == nullptr)
				pRoot = pCurr->pL;
			if (pCurr->rec.key > pPrev->rec.key)
				pPrev->pR = pCurr->pL;
			else
				pPrev->pL = pCurr->pL;
		}
		else if (pCurr->pL == nullptr)
		{
			if (pPrev == nullptr)
				pRoot = pCurr->pR;
			if (pCurr->rec.key > pPrev->rec.key)
				pPrev->pR = pCurr->pR;
			else
				pPrev->pL = pCurr->pR;
		}
		else
		{
			tmp = tmp->pL;
			pPrev = pCurr;
			while (tmp->pR != nullptr)
			{
				pPrev = tmp;
				tmp = tmp->pR;
			}
			pCurr->rec = tmp->rec;
			if (pCurr->pL == tmp)
				pPrev->pL = tmp->pL;
			else
				pPrev->pR = tmp->pL;
			delete tmp;
		}
		DataCount--;
		Eff++;
		return true;
	}

	void Reset()
	{
		currPos = 0;
		pCurr = pRoot;
		st.Clear();
		if (pCurr)
		{
			while (pCurr->pL)
			{
				st.Push(pCurr);
				pCurr = pCurr->pL;
			}
		}
		st.Push(pCurr);
	}

	bool GoNext()
	{
		pCurr = st.Pop();
		if (pCurr)
		{
			if (pCurr->pR)
			{
				pCurr = pCurr->pR;
				while (pCurr->pL)
				{
					st.Push(pCurr);
					pCurr = pCurr->pL;
				}
				st.Push(pCurr);
			}
			else
			{
				if (!st.Empty())
				{
					pCurr = st.Top();
				}
			}
			currPos++;
			return true;
		}
		return false;
	}

	bool IsEnd() { return currPos == DataCount; }

	void DelTree(TNode* p)
	{
		if (p)
		{
			DelTree(p->pL);
			DelTree(p->pR);
			delete p;
		}
	}

	void PrintRec(ostream& os, TNode* p, int level)
	{
		if (p) {
			for (int i = 0; i < level; i++)
				os << ' ';
			os << p->rec.key << endl;
			PrintRec(os, p->pL, level + 1);
			PrintRec(os, p->pR, level + 1);
		}
	}

	void Print(ostream& os) 
	{
		PrintRec(os, pRoot, 0);
	}

	TRecord GetCurrRec() const
	{
		return pCurr->rec;
	}

	bool IsFull() const { return false; }
};

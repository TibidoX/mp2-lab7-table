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
				pCurr = pCurr->pLeft;
			}
			else
			{
				pCurr = pCurr->pRight;
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
				pCurr->pRight = tmp;
			}
			else {
				pCurr->pLeft = tmp;
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
		if (pCurr->pRight == nullptr)
		{
			if (pPrev == nullptr)
				pRoot = pCurr->pLeft;
			if (pCurr->rec.key > pPrev->rec.key)
				pPrev->pRight = pCurr->pLeft;
			else
				pPrev->pLeft = pCurr->pLeft;
		}
		else if (pCurr->pLeft == nullptr)
		{
			if (pPrev == nullptr)
				pRoot = pCurr->pRight;
			if (pCurr->rec.key > pPrev->rec.key)
				pPrev->pRight = pCurr->pRight;
			else
				pPrev->pLeft = pCurr->pRight;
		}
		else
		{
			tmp = tmp->pLeft;
			pPrev = pCurr;
			while (tmp->pRight != nullptr)
			{
				pPrev = tmp;
				tmp = tmp->pRight;
			}
			pCurr->rec = tmp->rec;
			if (pCurr->pLeft == tmp)
				pPrev->pLeft = tmp->pLeft;
			else
				pPrev->pRight = tmp->pLeft;
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
			while (pCurr->pLeft)
			{
				st.Push(pCurr);
				pCurr = pCurr->pLeft;
			}
		}
		st.Push(pCurr);
	}

	bool GoNext()
	{
		pCurr = st.Pop();
		if (pCurr)
		{
			if (pCurr->pRight)
			{
				pCurr = pCurr->pRight;
				while (pCurr->pLeft)
				{
					st.Push(pCurr);
					pCurr = pCurr->pLeft;
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
			DelTree(p->pLeft);
			DelTree(p->pRight);
			delete p;
		}
	}

	void PrintRec(ostream& os, TNode* p, int level)
	{
		if (p) {
			for (int i = 0; i < level; i++)
				os << ' ';
			os << p->rec.key << endl;
			PrintRec(os, p->pLeft, level + 1);
			PrintRec(os, p->pRight, level + 1);
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

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
	TTreeTable() {
		pRoot = NULL;
		pCurr = NULL;
		pPrev = NULL;
		currPos = 0;
	}

	bool Find(TKey key) {
		pCurr = pRoot;
		pPrev = NULL;

		while (pCurr != NULL) {

			Eff++;
			if (pCurr->rec.key == key) return true;
			pPrev = pCurr;

			if (pCurr->rec.key > key) {
				pCurr = pCurr->pL;
			}
			else {
				pCurr = pCurr->pR;
			}
		}

		pCurr = pPrev;
		return false;
	}

	bool Insert(TRecord rec) {
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
		Eff++;
		DataCount++;
		return true;
	}

	bool Delete(TKey key) {
		if (!Find(key)) return false;
		TNode* tmp = pCurr;

		if (pCurr->pR == NULL) {
			if (pPrev == NULL) {
				pRoot = pCurr->pL;
			}
			else {
				if (pCurr->rec.key > pPrev->rec.key) {
					pPrev->pR = pCurr->pL;
				}
				else {
					pPrev->pL = pCurr->pL;
				}
			}
		}
		else if (pCurr->pL == NULL) {
			if (pPrev == NULL) {
				pRoot = pCurr->pR;
			}
			else {
				if (pCurr->rec.key > pPrev->rec.key) {
					pPrev->pL = pCurr->pR;
				}
				else {
					pPrev->pR = pCurr->pR;
				}
			}
		}
		else {
			tmp = tmp->pL;
			pPrev = pCurr;

			while (tmp->pR != NULL) {
				pPrev = tmp;
				tmp = tmp->pR;
			}

			pCurr->rec = tmp->rec;
			if (pCurr->pL == tmp) {
				pPrev->pL = tmp->pL;
			}
			else {
				pPrev->pR = tmp->pL;
			}

			delete tmp;
		}

		DataCount--;
		Eff++;
		return true;
	}

	TRecord GetCurrRec() const { return pCurr->rec; }


	void Reset() {
		currPos = 0;
		pCurr = pRoot;
		st.Clear();
		if (pCurr) {
			while (pCurr->pL) {
				st.Push(pCurr);
				pCurr = pCurr->pL;
			}
		}
		st.Push(pCurr);
	}

	bool GoNext() {
		pCurr = st.Top();
		st.Pop();

		if (pCurr) {
			if (pCurr->pR) {
				pCurr = pCurr->pR;

				while (pCurr->pL) {
					st.Push(pCurr);
					pCurr = pCurr->pL;
				}
				st.Push(pCurr);

			}
			else {
				if (!st.Empty()) {
					pCurr = st.Top();
				}
			}
			currPos++;
		}
		return true;
	}

	bool IsEnd() { return currPos == DataCount; }

	void PrintRec(std::ostream& os, TNode* node, int level) {
		if (node) {
			for (int i = 0; i < level; i++) {
				os << ' ';
			}

			os << node->rec.key << std::endl;
			PrintRec(os, node->pL, level + 1);
			PrintRec(os, node->pR, level + 1);
		}
	}

	void Print(std::ostream& os) {
		PrintRec(os, pRoot, 0);
		os << std::endl;
	}

	void DelTree(TNode* p)
	{
		if (p)
		{
			DelTree(p->pL);
			DelTree(p->pR);
			delete p;
		}
	}

	bool IsFull() const { return false; }
};

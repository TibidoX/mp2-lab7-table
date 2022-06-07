#pragma once

#include "TTreeTable.h"
class TBalTree : public TTreeTable
{
public:
	int LeftTreeBalIns(TNode*& p) {
		Eff++;
		int result = 0;

		if (p->balance == 1) {
			p->balance = 0;
			result = 0;
		}
		else if (p->balance == 0) {
			p->balance = -1;
			result = 1;
		}
		else {
			TNode* leftNode = p->pL;

			if (leftNode->balance == -1) {
				p->pL = leftNode->pR;
				leftNode->pR = p;
				p->balance = 0;
				leftNode->balance = 0;
				result = 0;
				p = leftNode;
			}
			else if (leftNode->balance == 1) {
				TNode* rightNode = leftNode->pR;

				leftNode->pR = rightNode->pR;
				p->pL = rightNode->pR;
				rightNode->pL = leftNode;
				rightNode->pR = p;

				if (rightNode->balance == -1) {
					rightNode->balance = 0;
					leftNode->balance = 1;
					p->balance = 1;
				}
				else {
					rightNode->balance = 1;
					leftNode->balance = 0;
					p->balance = 0;
				}

				result = 0;
				p = rightNode;
			}
		}

		return result;
	}

	int RightTreeBalIns(TNode*& p) {
		Eff++;
		int result = 0;

		if (p->balance == 0) {
			p->balance = 1;
			result = 1;
		}
		else if (p->balance == -1) {
			p->balance = 0;
			result = 0;
		}
		else {
			TNode* rightNode = p->pR;

			if (rightNode->balance == 1) {
				p->pR = rightNode->pL;
				rightNode->pL = p;
				p->balance = 0;
				rightNode->balance = 0;
				result = 0;
				p = rightNode;
			}
			else if (rightNode->balance == -1) {
				TNode* leftNode = rightNode->pL;

				rightNode->pL = leftNode->pR;
				p->pR = leftNode->pL;
				leftNode->pR = rightNode;
				leftNode->pL = p;

				if (leftNode->balance == -1) {
					rightNode->balance = 0;
					leftNode->balance = -1;
					p->balance = 0;
				}
				else {
					rightNode->balance = -1;
					leftNode->balance = 0;
					p->balance = -1;
				}

				result = 0;
				p = leftNode;
			}
		}

		return result;
	}

	int LeftTreeBalDel(TNode*& p) {
		Eff++;
		int result = 0;

		if (p->balance == 1)
		{
			p->balance = 0;
			result = -1;
		}
		else if (p->balance == 0)
		{
			p->balance = -1;
			result = 0;
		}
		else {
			TNode* leftNode = p->pL;

			if (leftNode->balance == -1)
			{
				p->pL = leftNode->pR;
				leftNode->pR = p;

				leftNode->balance = 0;
				p->balance = 0;

				p = leftNode;
				result = -1;
			}
			else if (leftNode->balance == 1)
			{
				TNode* plpr = leftNode->pR;

				leftNode->pR = plpr->pL;
				plpr->pL = leftNode;
				p->pL = plpr->pR;
				plpr->pR = p;
				if (plpr->balance == -1)
				{
					p->balance = 1;
				}
				else
				{
					p->balance = 0;
				}
				if (plpr->balance == 1)
				{
					leftNode->balance = -1;
				}
				else
				{
					leftNode->balance = 0;
				}
				p = plpr;
				p->balance = 0;
				result = -1;
			}
			else
			{
				TNode* pp = p;
				TNode* plpl = leftNode->pL;
				TNode* plpr = leftNode->pR;

				p = leftNode;
				p->pL = plpl;
				p->pR = pp;
				pp->pL = plpr;
				leftNode->balance = 1;
				return 0;
			}
		}
		return result;
	}

	int RightTreeBalDel(TNode*& p) {
		Eff++;
		int result = 0;

		if (p->balance == -1)
		{
			p->balance = 0;
			result = -1;
		}
		else if (p->balance == 0)
		{
			p->balance = 1;
			result = 0;
		}
		else
		{
			TNode* rightNode = p->pR;
			if (rightNode->balance == 1)
			{
				p->pR = rightNode->pL;
				rightNode->pL = p;

				rightNode->balance = 0;
				p->balance = 0;

				p = rightNode;
				result = -1;
			}
			else if (rightNode->balance == -1)
			{
				TNode* prpl = rightNode->pL;

				rightNode->pL = prpl->pR;
				prpl->pR = rightNode;
				p->pR = prpl->pL;
				prpl->pL = p;
				if (prpl->balance == 1)
				{
					p->balance = -1;
				}
				else
				{
					p->balance = 0;
				}
				if (prpl->balance == -1)
				{
					rightNode->balance = 1;
				}
				else
				{
					rightNode->balance = 0;
				}
				p = prpl;
				p->balance = 0;
				result = -1;
			}
			else
			{
				TNode* pp = p;
				TNode* prpl = rightNode->pL;
				TNode* prpr = rightNode->pR;

				p = rightNode;
				p->pL = pp;
				p->pR = prpr;
				pp->pR = prpl;
				rightNode->balance = -1;
				return 0;
			}
		}
		return result;
	}

	int InsBalTree(TNode*& p, TRecord rec) {
		Eff++;
		int result = 0;

		if (p == NULL) {
			p = new TNode(rec);
			result = 1;
			DataCount++;
		}
		else if (p->rec.key > rec.key) {
			int tmp = InsBalTree(p->pL, rec);

			if (tmp == 1) {
				result = LeftTreeBalIns(p);
			}
		}
		else {
			int tmp = InsBalTree(p->pR, rec);

			if (tmp == 1) {
				result = RightTreeBalIns(p);
			}
		}

		return result;
	}

	int DelBalTree(TNode*& p, TKey key) {
		Eff++;
		int result = 0;

		if (p == NULL) {
			return result;
		}
		if (key > p->rec.key) {
			int tmp = DelBalTree(p->pR, key);

			if (tmp != 0) {
				result = LeftTreeBalDel(p);
			}
		}
		else if (key < p->rec.key) {
			int tmp = DelBalTree(p->pL, key);

			if (tmp != 0) {
				result = RightTreeBalDel(p);
			}
		}
		else if (key == p->rec.key) {
			DataCount--;
			if (p->pL == NULL && p->pR == NULL) {
				delete p;
				p = NULL;
				result = -1;
			}
			else if (p->pL != NULL && p->pR == NULL) {
				p->rec = p->pL->rec;
				delete p->pL;
				p->pL = NULL;
				p->balance = 0;
				result = -1;
			}
			else if (p->pL == NULL && p->pR != NULL) {
				p->rec = p->pR->rec;
				delete p->pR;
				p->pR = NULL;
				p->balance = 0;
				result = 1;
			}
			else {
				TNode* leftNode = p->pL;
				TNode* rightNode = p->pR;
				TNode* pMax = FindMax(leftNode);

				p->rec = pMax->rec;
				int tmp = DelBalTree(p->pL, pMax->rec.key);

				if (tmp != 0) {
					result = RightTreeBalDel(p->pR);
				}
			}
		}
		return result;
	}

	TNode* FindMax(TNode* p) const {
		while (p->pR != NULL) {
			p = p->pR;
		}
		return p;
	}

	bool Insert(TRecord rec) {
		if (Find(rec.key)) return false;

		InsBalTree(pRoot, rec);
		return true;
	}

	bool Delete(TKey key) {
		if (!Find(key)) return false;

		DelBalTree(pRoot, key);
		return true;
	}

};
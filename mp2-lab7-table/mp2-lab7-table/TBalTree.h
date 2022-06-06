#pragma once

#include "TTreeTable.h"
class TBalTree : public TTreeTable
{
//    int LeftTreeBalIns(TNode*& p)
//    {
//        int res = 0; // did height change
//        Eff++;
//        if (p->bal == 1)
//        {
//            p->bal = 0;
//            res = 0;
//
//        }
//        else if (p->bal == 0)
//        {
//            p->bal = -1;
//            res = 1;
//        }
//        else
//        {
//            TNode* left = p->pL;
//            if (left->bal == -1) // перевес в левом поддереве слева
//            {
//                p->pL = left->pR;
//                left->pR = p;
//                p->bal = left->bal = 0;
//                p = left;
//            }
//            else if (left->bal == 1) // перевес в левом поддереве справа
//            {
//                TNode* right = left->pR;
//                left->pR = right->pL;
//                p->pL = right->pR;
//                right->pL = left;
//                right->pR = p;
//                if (right->bal == -1)
//                {
//                    right->bal = 0;
//                    left->bal = 1;// 0;
//                    p->bal = 1;
//                }
//                else
//                {
//                    right->bal = 1;// 0;
//                    left->bal = 0;//-1;
//                    p->bal = 0;
//                }
//                res = 0;
//                p = right;
//            }
//        }
//        return res;
//    }
//
//    int RightTreeBalIns(TNode*& p)
//    {
//        int res = 0; // did height change
//        Eff++;
//        if (p->bal == 0)
//        {
//            p->bal = 1;
//            res = 1;
//        }
//        else if (p->bal == -1)
//        {
//            p->bal = 0;
//            res = 0;
//        }
//        else
//        {
//            TNode* right = p->pR;
//            if (right->bal == 1) // перевес в правом поддереве справа
//            {
//                p->pR = right->pL;
//                right->pL = p;
//                p->bal = right->bal = 0;
//                p = right;
//            }
//            else if (right->bal == -1) // перевес в правом поддереве слева
//            {
//                TNode* left = right->pL;
//                right->pL = left->pR;
//                p->pR = left->pL;
//                left->pR = right;
//                left->pL = p;
//                if (left->bal == -1)
//                {
//                    left->bal = -1;// 0;
//                    right->bal = 0;
//                    p->bal = 0;// 1;
//                }
//                else
//                {
//                    left->bal = 0;
//                    right->bal = -1;
//                    p->bal = -1;// 0;
//                }
//                res = 0;
//                p = left;
//            }
//        }
//        return res;
//    }
//    int LeftTreeBalDel(TNode*& p)
//    {
//        int result = 0;
//
//        if (p->bal == 1)
//        {
//            p->bal = 0;
//            result = -1;
//        }
//        else if (p->bal == 0)
//        {
//            p->bal = -1;
//            result = 0;
//        }
//        else {
//            TNode* pl = p->pL;
//
//            if (pl->bal == -1)
//            {
//                p->pL = pl->pR;
//                pl->pR = p;
//
//                pl->bal = 0;
//                p->bal = 0;
//
//                p = pl;
//                result = -1;
//            }
//            else if (pl->bal == 1)
//            {
//                TNode* plpr = pl->pR;
//
//                pl->pR = plpr->pL;
//                plpr->pL = pl;
//                p->pL = plpr->pR;
//                plpr->pR = p;
//                if (plpr->bal == -1)
//                {
//                    p->bal = 1;
//                }
//                else
//                {
//                    p->bal = 0;
//                }
//                if (plpr->bal == 1)
//                {
//                    pl->bal = -1;
//                }
//                else
//                {
//                    pl->bal = 0;
//                }
//                p = plpr;
//                p->bal = 0;
//                result = -1;
//            }
//            else
//            {
//                TNode* pp = p;
//                TNode* plpl = pl->pL;
//                TNode* plpr = pl->pR;
//
//                p = pl;
//                p->pL = plpl;
//                p->pR = pp;
//                pp->pL = plpr;
//                pl->bal = 1;
//                return 0;
//            }
//        }
//        return result;
//    }
//    int RightTreeBalDel(TNode*& p)
//    {
//        int result = 0;
//        if (p->bal == -1)
//        {
//            p->bal = 0;
//            result = -1;
//        }
//        else if (p->bal == 0)
//        {
//            p->bal = 1;
//            result = 0;
//        }
//        else
//        {
//            TNode* pr = p->pR;
//            if (pr->bal == 1)
//            {
//                p->pR = pr->pL;
//                pr->pL = p;
//
//                pr->bal = 0;
//                p->bal = 0;
//
//                p = pr;
//                result = -1;
//            }
//            else if (pr->bal == -1)
//            {
//                TNode* prpl = pr->pL;
//
//                pr->pL = prpl->pR;
//                prpl->pR = pr;
//                p->pR = prpl->pL;
//                prpl->pL = p;
//                if (prpl->bal == 1)
//                {
//                    p->bal = -1;
//                }
//                else
//                {
//                    p->bal = 0;
//                }
//                if (prpl->bal == -1)
//                {
//                    pr->bal = 1;
//                }
//                else
//                {
//                    pr->bal = 0;
//                }
//                p = prpl;
//                p->bal = 0;
//                result = -1;
//            }
//            else
//            {
//                TNode* pp = p;
//                TNode* prpl = pr->pL;
//                TNode* prpr = pr->pR;
//
//                p = pr;
//                p->pL = pp;
//                p->pR = prpr;
//                pp->pR = prpl;
//                pr->bal = -1;
//                return 0;
//            }
//        }
//        return result;
//    }
//    int InsBalTree(TNode*& p, TRecord rec)
//    {
//        int res = 0;
//        if (p == nullptr)
//        {
//            p = new TNode(rec);
//            res = 1;
//            DataCount++;
//        }
//        else if (p->rec.key > rec.key)
//        {
//            int tmp = InsBalTree(p->pL, rec);
//            if (tmp == 1)
//            {
//                res = LeftTreeBalIns(p);
//            }
//        }
//        else
//        {
//            int tmp = InsBalTree(p->pR, rec);
//            if (tmp == 1)
//            {
//                res = RightTreeBalIns(p);
//            }
//        }
//        return res;
//    }
//    int DelBalance(TNode*& p, TKey key)
//    {
//        int res = 0;
//        Eff++;
//        if (p == nullptr)
//        {
//            return res;
//        }
//        if (key > p->rec.key)
//        {
//            int tmp = DelBalance(p->pR, key);
//            if (tmp != 0)
//            {
//                res = LeftTreeBalDel(p);
//            }
//        }
//        else if (key < p->rec.key)
//        {
//            int tmp = DelBalance(p->pL, key);
//            if (tmp != 0)
//            {
//                res = RightTreeBalDel(p);
//            }
//        }
//        else
//        {
//            DataCount--;
//            if (p->pL == nullptr && p->pR == nullptr) // удаление листа дерева
//            {
//                delete p;
//                p = nullptr;
//                res = -1;
//            }
//            else if (p->pL != nullptr && p->pR == nullptr) // удаление вершины с одним потомком слева
//            {
//                p->rec = p->pL->rec;
//                delete p->pL;
//                p->pL = nullptr;
//                p->bal = 0;
//                res = -1;
//            }
//            else if (p->pL == nullptr && p->pR != nullptr) // удаление вершины с одним потомком справа
//            {
//                p->rec = p->pR->rec;
//                delete p->pR;
//                p->pR = nullptr;
//                p->bal = 0;
//                res = 1;
//            }
//            else  // удаление вершины с двумя потомками
//            {
//                TNode* pl = p->pL, * pr = p->pR;
//                TNode* pmax = FindMax(pl);
//                p->rec = pmax->rec;
//                int tmp = DelBalance(p->pL, pmax->rec.key);
//                if (tmp != 0)
//                {
//                    res = RightTreeBalDel(p->pR);
//                }
//            }
//            return res;
//        }
//    }
//    TNode* FindMax(TNode* p) const
//    {
//        if (p) {
//            while (p->pR)
//                p = p->pR;
//            return p;
//        }
//    }
//public:
//    bool Insert(TRecord rec)
//    {
//        if (Find(rec.key))
//        {
//            return false;
//        }
//        InsBalTree(pRoot, rec);
//        return true;
//    }
//    bool Delete(TKey key)
//    {
//        if (!Find(key) || IsEmpty())
//        {
//            return false;
//        }
//        DelBalance(pRoot, key);
//        return true;
//    }

	/*int LeftTreeBalIns(TNode*& p) {
		Eff++;
		int result = 0;

		if (p->bal == 1) {
			p->bal = 0;
			result = 0;
		}
		else if (p->bal == 0) {
			p->bal = -1;
			result = 1;
		}
		else {
			TNode* pL = p->pL;

			if (pL->bal == -1) {
				p->pL = pL->pR;
				pL->pR = p;
				p->bal = 0;
				pL->bal = 0;
				result = 0;
				p = pL;
			}
			else if (pL->bal == 1) {
				TNode* pR = pL->pR;

				pL->pR = pR->pL;
				p->pL = pR->pR;
				pR->pL = pL;
				pR->pR = p;

				if (pR->bal == -1) {
					pR->bal == 0;
					pL->bal == 1;
					p->bal == 1;
				}
				else {
					pR->bal == 1;
					pL->bal == 0;
					p->bal == 0;
				}

				result = 0;
				p = pR;
			}
		}

		return result;
	}

	int RightTreeBalIns(TNode*& p) {
		Eff++;
		int result = 0;

		if (p->bal == 0) {
			p->bal = 1;
			result = 1;
		}
		else if (p->bal == -1) {
			p->bal = 0;
			result = 0;
		}
		else {
			TNode* pR = p->pR;

			if (pR->bal == 1) {
				p->pR = pR->pL;
				pR->pL = p;
				p->bal = 0;
				pR->bal = 0;
				result = 0;
				p = pR;
			}
			else if (pR->bal == -1) {
				TNode* pL = pR->pL;

				pR->pL = pL->pR;
				p->pR = pL->pL;
				pL->pR = pR;
				pL->pL = p;

				if (pL->bal == -1) {
					pR->bal == 0;
					pL->bal == -1;
					p->bal == 0;
				}
				else {
					pR->bal == -1;
					pL->bal == 0;
					p->bal == -1;
				}

				result = 0;
				p = pL;
			}
		}

		return result;
	}

	int LeftTreeBalDel(TNode*& p) {
		Eff++;
		int result = 0;

		if (p->bal == 1)
		{
			p->bal = 0;
			result = -1;
		}
		else if (p->bal == 0)
		{
			p->bal = -1;
			result = 0;
		}
		else {
			TNode* pl = p->pL;

			if (pl->bal == -1)
			{
				p->pL = pl->pR;
				pl->pR = p;

				pl->bal = 0;
				p->bal = 0;

				p = pl;
				result = -1;
			}
			else if (pl->bal == 1)
			{
				TNode* plpr = pl->pR;

				pl->pR = plpr->pL;
				plpr->pL = pl;
				p->pL = plpr->pR;
				plpr->pR = p;
				if (plpr->bal == -1)
				{
					p->bal = 1;
				}
				else
				{
					p->bal = 0;
				}
				if (plpr->bal == 1)
				{
					pl->bal = -1;
				}
				else
				{
					pl->bal = 0;
				}
				p = plpr;
				p->bal = 0;
				result = -1;
			}
			else
			{
				TNode* pp = p;
				TNode* plpl = pl->pL;
				TNode* plpr = pl->pR;

				p = pl;
				p->pL = plpl;
				p->pR = pp;
				pp->pL = plpr;
				pl->bal = 1;
				return 0;
			}
		}
		return result;
	}

	int RightTreeBalDel(TNode*& p) {
		Eff++;
		int result = 0;

		if (p->bal == -1)
		{
			p->bal = 0;
			result = -1;
		}
		else if (p->bal == 0)
		{
			p->bal = 1;
			result = 0;
		}
		else
		{
			TNode* pr = p->pR;
			if (pr->bal == 1)
			{
				p->pR = pr->pL;
				pr->pL = p;

				pr->bal = 0;
				p->bal = 0;

				p = pr;
				result = -1;
			}
			else if (pr->bal == -1)
			{
				TNode* prpl = pr->pL;

				pr->pL = prpl->pR;
				prpl->pR = pr;
				p->pR = prpl->pL;
				prpl->pL = p;
				if (prpl->bal == 1)
				{
					p->bal = -1;
				}
				else
				{
					p->bal = 0;
				}
				if (prpl->bal == -1)
				{
					pr->bal = 1;
				}
				else
				{
					pr->bal = 0;
				}
				p = prpl;
				p->bal = 0;
				result = -1;
			}
			else
			{
				TNode* pp = p;
				TNode* prpl = pr->pL;
				TNode* prpr = pr->pR;

				p = pr;
				p->pL = pp;
				p->pR = prpr;
				pp->pR = prpl;
				pr->bal = -1;
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
				p->bal = 0;
				result = -1;
			}
			else if (p->pL == NULL && p->pR != NULL) {
				p->rec = p->pR->rec;
				delete p->pR;
				p->pR = NULL;
				p->bal = 0;
				result = 1;
			}
			else {
				TNode* pL = p->pL;
				TNode* pR = p->pR;
				TNode* pMax = FindMax(pL);

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

public:
	bool Insert(TRecord rec) {
		if (Find(rec.key)) return false;

		InsBalTree(pRoot, rec);
		return true;
	}

	bool Delete(TKey key) {
		if (!Find(key)) return false;

		DelBalTree(pRoot, key);
		return true;
	}*/

	int LeftTreeBalIns(TNode*& p) {
		Eff++;
		int result = 0;

		if (p->bal == 1) {
			p->bal = 0;
			result = 0;
		}
		else if (p->bal == 0) {
			p->bal = -1;
			result = 1;
		}
		else {
			TNode* pL = p->pL;

			if (pL->bal == -1) {
				p->pL = pL->pR;
				pL->pR = p;
				p->bal = 0;
				pL->bal = 0;
				result = 0;
				p = pL;
			}
			else if (pL->bal == 1) {
				TNode* pR = pL->pR;

				pL->pR = pR->pL;
				p->pL = pR->pR;
				pR->pL = pL;
				pR->pR = p;

				if (pR->bal == -1) {
					pR->bal == 0;
					pL->bal == 1;
					p->bal == 1;
				}
				else {
					pR->bal == 1;
					pL->bal == 0;
					p->bal == 0;
				}

				result = 0;
				p = pR;
			}
		}

		return result;
	}

	int RightTreeBalIns(TNode*& p) {
		Eff++;
		int result = 0;

		if (p->bal == 0) {
			p->bal = 1;
			result = 1;
		}
		else if (p->bal == -1) {
			p->bal = 0;
			result = 0;
		}
		else {
			TNode* pR = p->pR;

			if (pR->bal == 1) {
				p->pR = pR->pL;
				pR->pL = p;
				p->bal = 0;
				pR->bal = 0;
				result = 0;
				p = pR;
			}
			else if (pR->bal == -1) {
				TNode* pL = pR->pL;

				pR->pL = pL->pR;
				p->pR = pL->pL;
				pL->pR = pR;
				pL->pL = p;

				if (pL->bal == -1) {
					pR->bal == 0;
					pL->bal == -1;
					p->bal == 0;
				}
				else {
					pR->bal == -1;
					pL->bal == 0;
					p->bal == -1;
				}

				result = 0;
				p = pL;
			}
		}

		return result;
	}

	int LeftTreeBalDel(TNode*& p) {
		Eff++;
		int result = 0;

		if (p->bal == 1)
		{
			p->bal = 0;
			result = -1;
		}
		else if (p->bal == 0)
		{
			p->bal = -1;
			result = 0;
		}
		else {
			TNode* pl = p->pL;

			if (pl->bal == -1)
			{
				p->pL = pl->pR;
				pl->pR = p;

				pl->bal = 0;
				p->bal = 0;

				p = pl;
				result = -1;
			}
			else if (pl->bal == 1)
			{
				TNode* plpr = pl->pR;

				pl->pR = plpr->pL;
				plpr->pL = pl;
				p->pL = plpr->pR;
				plpr->pR = p;
				if (plpr->bal == -1)
				{
					p->bal = 1;
				}
				else
				{
					p->bal = 0;
				}
				if (plpr->bal == 1)
				{
					pl->bal = -1;
				}
				else
				{
					pl->bal = 0;
				}
				p = plpr;
				p->bal = 0;
				result = -1;
			}
			else
			{
				TNode* pp = p;
				TNode* plpl = pl->pL;
				TNode* plpr = pl->pR;

				p = pl;
				p->pL = plpl;
				p->pR = pp;
				pp->pL = plpr;
				pl->bal = 1;
				return 0;
			}
		}
		return result;
	}

	int RightTreeBalDel(TNode*& p) {
		Eff++;
		int result = 0;

		if (p->bal == -1)
		{
			p->bal = 0;
			result = -1;
		}
		else if (p->bal == 0)
		{
			p->bal = 1;
			result = 0;
		}
		else
		{
			TNode* pr = p->pR;
			if (pr->bal == 1)
			{
				p->pR = pr->pL;
				pr->pL = p;

				pr->bal = 0;
				p->bal = 0;

				p = pr;
				result = -1;
			}
			else if (pr->bal == -1)
			{
				TNode* prpl = pr->pL;

				pr->pL = prpl->pR;
				prpl->pR = pr;
				p->pR = prpl->pL;
				prpl->pL = p;
				if (prpl->bal == 1)
				{
					p->bal = -1;
				}
				else
				{
					p->bal = 0;
				}
				if (prpl->bal == -1)
				{
					pr->bal = 1;
				}
				else
				{
					pr->bal = 0;
				}
				p = prpl;
				p->bal = 0;
				result = -1;
			}
			else
			{
				TNode* pp = p;
				TNode* prpl = pr->pL;
				TNode* prpr = pr->pR;

				p = pr;
				p->pL = pp;
				p->pR = prpr;
				pp->pR = prpl;
				pr->bal = -1;
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
				p->bal = 0;
				result = -1;
			}
			else if (p->pL == NULL && p->pR != NULL) {
				p->rec = p->pR->rec;
				delete p->pR;
				p->pR = NULL;
				p->bal = 0;
				result = 1;
			}
			else {
				TNode* pL = p->pL;
				TNode* pR = p->pR;
				TNode* pMax = FindMax(pL);

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

public:
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
#pragma once
#include "TTable.h"

struct TNode {
	TRecord rec;
	TNode* pL, * pR;
	int balance;

	TNode(TRecord rec, TNode* pLeft = NULL, TNode* pRight = NULL) : rec(rec), pL(pLeft), pR(pRight), balance(0) {}
};
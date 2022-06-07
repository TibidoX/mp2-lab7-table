#pragma once
#include "TTable.h"

struct TNode {
	TRecord rec;
	TNode* pLeft, * pRight;
	int balance;

	TNode(TRecord rec, TNode* pLeft = NULL, TNode* pRight = NULL) : rec(rec), pLeft(pLeft), pRight(pRight), balance(0) {}
};
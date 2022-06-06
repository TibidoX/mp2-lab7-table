#pragma once
#include "TTable.h"

struct TNode
{
	TRecord rec;
	TNode* pL, * pR;
	int pos, level;
	int bal = 0;

public:
	TNode(TRecord _rec)
	{
		rec = _rec;
		pL = nullptr;
		pR = nullptr;
	}
};
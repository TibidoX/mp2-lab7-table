#pragma once
#include "TTable.h"

struct TNode
{
	TRecord rec;
	TNode* pL, * pR;
	int pos, level;
};
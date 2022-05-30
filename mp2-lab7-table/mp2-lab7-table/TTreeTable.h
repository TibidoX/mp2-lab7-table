#pragma once
#include "TTable.h"
#include "TNode.h"
class TTreeTable:public TTable
{
protected:
	TNode* pRoot, * pCurr, * pPrev;
	TStack<TNode*> st;
public:

};

#include <iostream>
#include "TreeNode.h"
using namespace std;

#ifndef MYBST
#define MYBST

class myBST {
protected:
	BinNode* myRoot;

	void InOrderAux(ostream& out, BinNode* subTreePtr) const;
	void PreOrderAux(ostream& out, BinNode* subTreePtr) const;
	void PostOrderAux(ostream& out, BinNode* subTreePtr) const;
	void DisplayAux(ostream& out, int indent, BinNode* subTreePtr) const;
	void SearchForRemove(const int& item, bool& found, BinNode*& localPtr, BinNode*& parentPtr) const;

public:
	myBST();
	bool Empty() const;
	void InOrder(ostream& out) const;
	void PreOrder(ostream& out) const;
	void PostOrder(ostream& out) const;
	void Display(ostream& out) const;
	bool Search(const int& item) const;
	void Insert(const int& item);
	void Remove(const int& item);
};

#endif // !MYBST

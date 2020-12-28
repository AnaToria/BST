#include<iostream>
#include <iomanip>
#include "BST.h"
#include "TreeNode.h"
using namespace std;

myBST::myBST()
	:myRoot(NULL)
{}

bool myBST::Empty() const {
	return myRoot == NULL;
}

void myBST::InOrder(ostream& out) const {
	InOrderAux(out, myRoot);
}

void myBST::InOrderAux(ostream& out, BinNode* subTreeRoot) const {
	if (subTreeRoot != NULL) {
		InOrderAux(out, subTreeRoot->getLeft());  // L operation
		out << subTreeRoot->getData() << " ";    // V operation
		InOrderAux(out, subTreeRoot->getRight());   // R operation
	}
}

void myBST::PreOrder(ostream& out) const {
	PreOrderAux(out, myRoot);
}

void myBST::PreOrderAux(ostream& out, BinNode* subTreeRoot) const {
	if (subTreeRoot != NULL) {
		out << subTreeRoot->getData() << " ";  // V operation
		PreOrderAux(out, subTreeRoot->getLeft()); // L operation
		PreOrderAux(out, subTreeRoot->getRight());  // R operation
	}
}

void myBST::PostOrder(ostream& out) const {
	PostOrderAux(out, myRoot);
}

void myBST::PostOrderAux(ostream& out, BinNode* subTreeRoot) const {
	if (subTreeRoot != NULL) {
		PostOrderAux(out, subTreeRoot->getLeft()); // L operation
		PostOrderAux(out, subTreeRoot->getRight());  // R operation
		out << subTreeRoot->getData() << " ";  // V operation
	}
}

void myBST::Display(ostream& out) const {
	DisplayAux(out, 0, myRoot);
}

void myBST::DisplayAux(ostream& out, int indent, BinNode* subTreeRoot) const {
	if (subTreeRoot != NULL) {
		DisplayAux(out, indent + 8, subTreeRoot->getRight());
		out << setw(indent) << " " << subTreeRoot->getData() << endl;
		DisplayAux(out, indent + 8, subTreeRoot->getLeft());
	}
}

bool myBST::Search(const int& item) const {
	BinNode* localPtr = myRoot;
	bool found = false;

	while (!found && localPtr!=NULL){
		if (item < localPtr->getData())   // descend left
			localPtr = localPtr->getLeft();
		else if (item > localPtr->getData())   // descend right
			localPtr = localPtr->getRight();
		else
			found = true;  // item is found
	}

	return found;
}

void myBST::Insert(const int& item) {
	BinNode* localPtr = myRoot,   // search pointer
		*parentPtr = NULL;   // pointer to parent of current node
	bool found = false;  // indicates if item is already in BST

	while (!found && localPtr != NULL) {
		parentPtr = localPtr;
		if (item < localPtr->getData())   // descend left
			localPtr = localPtr->getLeft();
		else if (item > localPtr->getData())   // descend right
			localPtr = localPtr->getRight();
		else
			found = true;  // item is found
	}

	if (!found) {
		localPtr = new BinNode(item);  // constructing new node containing item

		if (parentPtr == NULL) // tree is empty
			myRoot = localPtr;
		else if (item < parentPtr->getData())   // insert to left of parent
			parentPtr->setLeft(localPtr);
		else
			parentPtr->setRight(localPtr);  //insert to right of parent
	}
	else
		cout << "\nItem is already in the tree" << endl;
}

void myBST::SearchForRemove(const int& item, bool& found, BinNode*& localPtr, BinNode*& parentPtr) const {
	localPtr = myRoot;
	parentPtr = NULL;
	found = false;

	while (!found && localPtr != NULL) {
		if (item < localPtr->getData()) {   // descend left
			parentPtr = localPtr;
			localPtr = localPtr->getLeft();
		}
		else if (item > localPtr->getData()) {  // descend right
			parentPtr = localPtr;
			localPtr = localPtr->getRight();
		}
		else
			found = true;  // item is found
	}
}

void myBST::Remove(const int& item) {
	bool found;
	BinNode* x,   // points to node to be deleted
		* parentPtr;  // points to node parent of x and xSucc

	SearchForRemove(item, found, x, parentPtr);

	if (!found) {
		cout << "Item is not in the BST" << endl;
		return;
	}

	if (x->getLeft() != NULL && x->getRight() != NULL) { // node has 2 children
		BinNode* xSucc=x->getRight(); 
		parentPtr = x;
		
		while (xSucc->getLeft() != NULL) {  // descend left
			parentPtr = xSucc;
			xSucc = xSucc->getLeft();
		}

		// move contents of xSucc to x and x to point to successor, which will be removed
		x->setData(xSucc->getData());
		x = xSucc;
	}

	// node has 0 or 1 child
	BinNode* subTreePtr = x->getLeft();
	if (subTreePtr == NULL)
		subTreePtr = x->getRight();  

	if (parentPtr == NULL) // root being removed
		myRoot = subTreePtr;
	else if (parentPtr->getLeft() == x) // left child
		parentPtr->setLeft(subTreePtr);
	parentPtr->setRight(subTreePtr);  // right child

	delete x;
}

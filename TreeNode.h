#include<iostream>
using namespace std;

#ifndef BINNODE
#define BINNODE

class BinNode {
protected:
	int data;
	BinNode* right;
	BinNode* left;

public:
	friend class BST;
	BinNode();
	BinNode(int item);
	int getData() const;
	BinNode* getRight() const;
	BinNode* getLeft() const;
	void setData(int item);
	void setRight(BinNode* rightPtr);
	void setLeft(BinNode* leftPtr);
};

inline BinNode::BinNode()
	:right(NULL), left(NULL)
{}

inline BinNode::BinNode(int item)
	:data(item), right(NULL), left(NULL)
{}

inline int BinNode::getData() const {
	return data;
}

inline BinNode* BinNode::getRight() const {
	return right;
}

inline BinNode* BinNode::getLeft() const {
	return left;
}

inline void BinNode::setData(int item) {
	this->data = item;
}

inline void BinNode::setRight(BinNode* rightPtr) {
	this->right = rightPtr;
}

inline void BinNode::setLeft(BinNode* leftPtr) {
	this->left = leftPtr;
}
#endif // !BINNODE

#include<iostream>
#include "BST.h"
using namespace std;

int main() {
	myBST bst;
	// testing empty function
	cout << "BST is constructing. Is it empty? " << boolalpha << bst.Empty() << endl;

	// testing insertion function
	cout << "Enter integer into tue BST. \nTry items not in the BST and some thar are in it: " << endl;
	int number;
	while (true) {
		cout << "Item to insert (-999 to stop insertion) : ";
		cin >> number;
		if (number == -999)
			break;
		bst.Insert(number);
	}

	cout << "Is BST empty? " << boolalpha << bst.Empty() << endl;

	bst.Display(cout);   // testing display
	cout << "\nPreorder traversal : " << endl;
	bst.PreOrder(cout);   // testing preorder 
	cout << "\nInOrder traversal : " << endl;
	bst.InOrder(cout);   // testing inorder
	cout << "\nPostOrder traversal : " << endl;
	bst.PostOrder(cout);  // testing postorder

	// testing search function
	cout << "\n\nTry to search both items in the BST and some not in it : " << endl;
	while (true) {
		cout << "Item to search (-999 to stop insertion) : ";
		cin >> number;
		if (number == -999)
			break;
		cout << number << (bst.Search(number) ? "is found" : "is not found") << endl;
	}

	// testing remove function
	cout << "Try to remove both items in the BST and some not in it : " << endl;
	while (true) {
		cout << "Item to remove (-999 to stop insertion) : ";
		cin >> number;
		if (number == -999)
			break;
		bst.Remove(number);
		bst.Display(cout);
	}
	cout << "Preorder traversal : " << endl;
	bst.PreOrder(cout);

}
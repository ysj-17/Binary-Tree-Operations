
#include <iostream>
#include <vector>
#include <fstream>
#include "BinaryTree.h"
using namespace std;


template <typename T>
void iterativeInOrder(TreeNode<T> *&tree);

template <typename T>
void iterativePreOrder(TreeNode<T> *&tree);

template <typename T>
void iterativePostOrder(TreeNode<T> *&tree);


int main()
{
	vector<int> numbers;
	TreeNode<int>* root = NULL;

	ifstream inputFile("Numbers.txt", ios::in);

	int number;

	while (inputFile >> number) {
		numbers.push_back(number);
	}

	BinarySearchTree<int> bst;

	for (int index = 0; index < numbers.size(); index++)
		bst.insert(numbers[index], bst.root);
	
	int choice = 0;
	cout << "Please input choice\n1. Iterative In-Order  2. Iterative Pre-Order  3. Iterative Post-Order\n";
	cin >> choice;

	switch (choice) {
	case 1: iterativeInOrder(bst.root);
		break;
	case 2: iterativePreOrder(bst.root);
		break;
	case 3: iterativePostOrder(bst.root);
		break;
	}

	cin.ignore();
	cin.get();
	return 0;
}

template <typename T>
void iterativeInOrder(TreeNode<T> *&tree) {

	if (tree == NULL)
		return;

	Stack<int> nodeStack;
	TreeNode<T>* nodePtr = tree;
	TreeNode<T>*s = NULL;
	bool done = false;

	while (!done) {
		if (nodePtr != NULL) {
			nodeStack.add(nodePtr);
			nodePtr = nodePtr->left;
		}
		else {
			if (nodeStack.isEmpty() == false) {
				nodePtr = nodeStack.remove();
				cout << nodePtr->data << endl;
				nodePtr = nodePtr->right;
			}
			else
				done = true;
		}
	}
	cout << "Will now clear the InOrder Stack\n";
	nodeStack.clear();

}


template <typename T>
void iterativePreOrder(TreeNode<T> *&tree) {
	if (tree == NULL)
		return;

	Stack<int> nodeStack;
	nodeStack.add(tree);

	while (nodeStack.isEmpty() == false) {
		TreeNode<T> *nodePtr = nodeStack.Top();
		cout << nodePtr->data << endl;
		nodePtr = nodeStack.remove();

		if (nodePtr->right)
			nodeStack.add(nodePtr->right);
		if (nodePtr->left)
			nodeStack.add(nodePtr->left);
	}

	cout << "Will not clear the PreOrder Stack\n";
	nodeStack.clear();
}

template <typename T>
void iterativePostOrder(TreeNode<T> *&tree) {
	if (tree == NULL)
		return;

	Stack<int> stackOne;
	Stack<int> stackTwo;


	stackOne.add(tree);
	TreeNode<T> *nodePtr;


	while (stackOne.isEmpty() == false)
	{
		
		nodePtr = stackOne.remove();
		stackTwo.add(nodePtr);

	
		if (nodePtr->left)
			stackOne.add(nodePtr->left);
		if (nodePtr->right)
			stackOne.add(nodePtr->right);
	}


	while (stackTwo.isEmpty() == false)
	{
		nodePtr = stackTwo.remove();
		cout << nodePtr->data << endl;
	}

	cout << "Will not clear the PostOrder Stacks\n";
	stackOne.clear();
	stackTwo.clear();
}
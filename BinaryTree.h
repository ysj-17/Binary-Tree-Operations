#ifndef LAB5_BINARY_TREE
#define LAB5_BINARY_TREE
#include <iostream>
using namespace std;

template <class T>
class TreeNode {
public:
	T data;
	TreeNode<T>* left;
	TreeNode<T>* right;
	TreeNode<T>* prev;
	TreeNode<T>* next;
	TreeNode() {};
	TreeNode(T input) {
		data = input;
		left = NULL;
		right = NULL;
	};
};


template <typename T>
class Stack
{
	TreeNode<T>* top;
public:
	// Clear is the Destructor
	Stack() { top = NULL; }
	Stack(T t) { add(t); }

	void clear() {
		TreeNode<T> *nodePtr = top;
		TreeNode<T> *n;
		while (nodePtr) {
			n = nodePtr->prev;
			delete nodePtr; // delete Dynamic memory
			nodePtr = n;
		}
		top = nullptr; // point top to null 
		cout << "List has been cleared!" << endl;
	}

	bool add(TreeNode<T> *newEntry) {
		TreeNode<T> *newNode = new TreeNode<T>;
		newNode = newEntry;

		if (isEmpty() == true) {
			top = newNode;
			newNode->prev = NULL;
		}
		else {
			newNode->prev = top;
			top = newNode;
		}
		return true;
	}

	// Remove acts like the Pop function, for display purposes only
	TreeNode<T>* remove() {
		if (isEmpty() == true) {
			cout << "The list is empty!" << endl;
		}
		else {
			TreeNode<T> *rover = top;
			TreeNode<T> *container = rover;
			top = top->prev;
			return container;
		}
	}


	bool isEmpty() {
		if (!top)
			return true;
		else  return false;
	}


	TreeNode<T>* Top()
	{
		return top;
	}
};

template <typename T>
class BinarySearchTree
{
public:

	Stack<T> stack;
	TreeNode<T>* root;

	BinarySearchTree() {};
	BinarySearchTree(T input)
	{
		root = new TreeNode<T>(input);
	}

	~BinarySearchTree() { delete root; }

	void insert(T x, TreeNode<T> *&tree) {
		if (tree == NULL) {
			tree = new TreeNode<T>(x);
		}
		else if (x < tree->data)
			insert(x, tree->left);
		else if (x > tree->data)
			insert(x, tree->right);
	}

	bool search(T x, TreeNode<T> *&tree)
	{
		if (tree == NULL) {
			return false;
		}
		else if (tree->data = x) {
			return true;
		}
		else if (tree->data >= x) {
			return search(x, tree->left);
		}
		else {
			return search(x, tree->right);
		}
	}

};








#endif